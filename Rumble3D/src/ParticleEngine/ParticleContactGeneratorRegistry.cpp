#include "R3D/ParticleEngine/ParticleContactGeneratorRegistry.h"

#include <algorithm>

namespace r3
{
	ParticleContactGeneratorRegistry::ParticleContactGeneratorRegistry()
	= default;

	ParticleContactGeneratorRegistry::~ParticleContactGeneratorRegistry()
	= default;

	void ParticleContactGeneratorRegistry::registerContactGenerator(ParticleContactGenerator* generator)
	{
		m_contactGenerators.push_back(generator);
	}

	bool ParticleContactGeneratorRegistry::unregisterContactGenerator(ParticleContactGenerator* generator)
	{
		const auto foundGenerator = std::remove(m_contactGenerators.begin(),
												m_contactGenerators.end(),
												generator);

		bool found = foundGenerator != m_contactGenerators.end();
		m_contactGenerators.erase(foundGenerator, m_contactGenerators.end());

		return found;
	}

	void ParticleContactGeneratorRegistry::clear()
	{
		m_contactGenerators.clear();
	}

	const std::vector<ParticleContactGenerator*>& ParticleContactGeneratorRegistry::getGenerators() const
	{
		return m_contactGenerators;
	}
}
