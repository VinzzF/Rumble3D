#pragma once
#include "CollisionSphere.h"
#include "CollisionBox.h"
#include "CollisionPlane.h"
#include "CollisionData.h"

#include <glm/glm.hpp>

namespace rum
{
	// Beh�lter f�r Kollisionsalgorithmen:
	class CollisionDetector
	{
	public:
		static unsigned sphereAndHalfSpace(
			const CollisionSphere &sphere,
			const CollisionPlane &plane,
			CollisionData *data);

		static unsigned sphereAndTruePlane(
			const CollisionSphere &sphere,
			const CollisionPlane &plane,
			CollisionData *data);

		static unsigned sphereAndSphere(
			const CollisionSphere &one,
			const CollisionSphere &two,
			CollisionData *data);

		static unsigned boxAndHalfSpace(
			const CollisionBox &box,
			const CollisionPlane &plane,
			CollisionData *data);

		static unsigned boxAndSphere(
			const CollisionBox &box,
			const CollisionSphere &sphere,
			CollisionData *data);

		static unsigned boxAndBox(
			const CollisionBox &one,
			const CollisionBox &two,
			CollisionData *data);
	private:
		static real transformToAxis(
			const CollisionBox &box,
			const glm::vec3 &axis);
		/*
		* �berlappen zweier Quader entlang einer Achse.
		* R�ckgabe ist der Wert der �berlappung.
		* toCentre ist der Vektor zwischen den Quadern und wird
		* �bergeben, um nicht immer neu berechnet werden zu m�ssen.
		*/
		static real penetrationOnAxis(
			const CollisionBox &one,
			const CollisionBox &two,
			const glm::vec3 &axis,
			const glm::vec3 &toCentre);

		//SAT-Test, ob bzgl.einer Achse eine �berlappung stattfindet.
		static bool tryAxis(
			const CollisionBox &one,
			const CollisionBox &two,
			glm::vec3 axis,
			const glm::vec3& toCentre,
			unsigned index,
			// INOUT-Parameter
			real& smallestPenetration,
			unsigned &smallestCase);

		// Erstellt die Kontaktdaten f�r den Fall BoxBox-Kollision
		// wenn der Kontakt Ecke-Fl�che ist:
		static void fillPointFaceBoxBox(
			const CollisionBox &one,
			const CollisionBox &two,
			const glm::vec3 &toCentre,
			CollisionData *data,
			unsigned best,
			real pen);

		static glm::vec3 contactPoint(
			const glm::vec3 &pOne,
			const glm::vec3 &dOne,
			real oneSize,
			const glm::vec3 &pTwo,
			const glm::vec3 &dTwo,
			real twoSize,
			// useOne = true und Kontaktpunkt au�erhalb der Kante
			// (Kante-Fl�che-Kontakt) dann nehmen wir den Mittelpunkt
			// von Quader 1, sonst von Quader 2.
			bool useOne);
	};
}
