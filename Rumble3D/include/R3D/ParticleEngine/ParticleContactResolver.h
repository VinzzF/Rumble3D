#pragma once
#include "R3D/Common/Common.h"
#include "R3D/Common/Precision.h"
#include "R3D/ParticleEngine/ParticleContact.h"
#include "R3D/Utility/FixedSizeContainer.h"

#include <cstdint>

namespace r3
{
    /**
	 * \brief A ParticleContactResolver resolves a given number of contacts.
	 */
	class R3D_DECLSPEC ParticleContactResolver
	{
	public:
		explicit ParticleContactResolver(uint32_t iterations);
		~ParticleContactResolver() = default;

		/**
		 * \brief Set maximal number of iterations used. 
		 * \param iterations The new maximal number of iterations.
		 */
		void setIterationsMax(uint32_t iterations);
	
		/**
		* \brief Resolve collision and penetration. 
		* \param contactData The contacts to be resolved.
		* \param duration Time step used for this update.
		*/
		void resolveContacts(FixedSizeContainer<ParticleContact>& contactData,
							 real duration);

	protected:
        uint32_t m_iterationsMax;
        uint32_t m_iterationsUsed;
	};
}
