#include "R3D/RigidBodyEngine/ForceRegistry.h"
#include "R3D/RigidBodyEngine/ForceGenerator.h"
#include "R3D/RigidBodyEngine/RigidBody.h"

#include <algorithm>

namespace r3
{
	void ForceRegistry::unregisterForce(RigidBody* rigidBody, ForceGenerator* generator)
	{
		auto it_rem = std::remove_if(m_registrations.begin(), m_registrations.end()
			, [=](const ForceRegistrationEntry& fre) { return fre.m_rigidBody == rigidBody && fre.m_forceGenerator == generator; });

		m_registrations.erase(it_rem, m_registrations.end());
	}
	
	void ForceRegistry::clear()
	{
		m_registrations.clear();
	}

	ForceRegistry::ForceRegistry()
	= default;

	ForceRegistry::~ForceRegistry()
	= default;

	void ForceRegistry::registerForce(RigidBody* rigidBody, ForceGenerator* generator)
	{
		ForceRegistrationEntry registration{};
		registration.m_rigidBody = rigidBody;
		registration.m_forceGenerator = generator;
		m_registrations.push_back(registration);
	}
	
	void ForceRegistry::updateForces()
	{
		for (auto& i : m_registrations)
		{
			i.m_forceGenerator->updateForce(i.m_rigidBody);
		}
	}
}
