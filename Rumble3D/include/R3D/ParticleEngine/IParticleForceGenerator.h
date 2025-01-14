#pragma once
#include "R3D/Common/Common.h"
#include "R3D/Common/Precision.h"

namespace r3
{
	class Particle;

	/**
	 * Interface for particle force generators.
	 */
	class R3D_DECLSPEC IParticleForceGenerator
	{
	public:
		virtual ~IParticleForceGenerator();

		/**
		 * \brief Calculates and changes the force in the force accumulator
		 * of a particle.
		 * \param particle The particle, on which the force should be applied to.
		 */
		virtual void updateForce(Particle* particle) = 0;

	protected:
		explicit IParticleForceGenerator();
	};
}