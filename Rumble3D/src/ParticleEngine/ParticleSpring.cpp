#include "R3D/ParticleEngine/ParticleSpring.h"
#include "R3D/ParticleEngine/Particle.h"

#include <glm/glm.hpp>

namespace r3
{
	ParticleSpring::ParticleSpring(Particle* other, 
								   const real springConstant,
								   const real restLength)
		: m_springConstant{springConstant},
		m_restLength{restLength},
		m_other{other}
	{
	}
	
	ParticleSpring::~ParticleSpring()
	= default;

	void ParticleSpring::updateForce(Particle* particle)
	{
		// Feather length
		auto force = particle->getPosition();
		force -= m_other->getPosition();
	
		// Force magnitude is needed for direction 
		auto magnitude = glm::length(force);
		if(magnitude == real(0))
		{
			return;
		}
		magnitude -= m_restLength;
		magnitude *= m_springConstant;
	
		//Resultierende Federkraft und Anwendung auf Teilchen:
		force = glm::normalize(force);
		force *= -magnitude;
		particle->addForce(force);
	}
}