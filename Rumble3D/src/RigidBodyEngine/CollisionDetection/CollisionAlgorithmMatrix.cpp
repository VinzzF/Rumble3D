#include "R3D/RigidBodyEngine/CollisionDetection/CollisionAlgorithmMatrix.h"
#include "R3D/RigidBodyEngine/CollisionDetection/INarrowPhaseAlgorithm.h"
#include "R3D/RigidBodyEngine/CollisionDetection/Algorithm/NullAlgorithm.h"

#include <cassert>

namespace r3
{
	CollisionAlgorithmMatrix::CollisionAlgorithmMatrix()
		: m_nullAlgorithm(nullptr)
	{
		init();
	}

	CollisionAlgorithmMatrix::~CollisionAlgorithmMatrix()
	{
		delete m_nullAlgorithm;
	}

	void CollisionAlgorithmMatrix::setAlgorithm(INarrowPhaseAlgorithm* algorithm,
	                                            const CollisionPrimitiveType firstShape,
	                                            const CollisionPrimitiveType secondShape)
	{
		freeMemory(firstShape, secondShape);
		freeMemory(secondShape, firstShape);

		m_algorithms[firstShape][secondShape] = algorithm;
		m_algorithms[secondShape][firstShape] = algorithm;
	}

	INarrowPhaseAlgorithm* CollisionAlgorithmMatrix::getAlgorithm(const CollisionPrimitiveType firstShape,
	                                                              const CollisionPrimitiveType secondShape)
	{
		const auto foundAlgorithm = m_algorithms[firstShape][secondShape];
		return foundAlgorithm;
	}

	void CollisionAlgorithmMatrix::freeMemory(const CollisionPrimitiveType firstShape,
	                                          const CollisionPrimitiveType secondShape)
	{
		auto algorithm = m_algorithms[firstShape][secondShape];
		if(algorithm != m_nullAlgorithm)
		{
			delete algorithm;
			m_algorithms[firstShape][secondShape] = m_nullAlgorithm;
		}
	}

	void CollisionAlgorithmMatrix::init()
	{
		/// \todo: replace nullptr with NullAlgorithm
		//m_nullAlgorithm = nullptr;// new NullAlgorithm();
		for(int i = 0; i < s_algCount; ++i)
		{
			for(int j = 0; j < s_algCount; ++j)
			{
				m_algorithms[i][j] = m_nullAlgorithm;
			}
		}
	}
}
