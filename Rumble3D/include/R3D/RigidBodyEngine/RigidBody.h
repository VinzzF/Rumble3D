#pragma once
#include "R3D/RigidBodyEngine/CollisionObject.h"
#include "R3D/RigidBodyEngine/CollisionDetection/CollisionMask.h"
#include "R3D/RigidBodyEngine/RigidBodyDef.h"
#include "R3D/Common/Precision.h"
#include "R3D/Common/Common.h"

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include "R3D/Transform3D.h"


namespace r3 
{
	class PhysicsMaterial;

	class R3D_DECLSPEC RigidBody : public CollisionObject
	{
	public:
		explicit RigidBody();
		explicit RigidBody(const RigidBodyDef& def);
		~RigidBody();
	
		/** Initialize all attributes of this rigid body. */
		void init(const RigidBodyDef& definition);

		void calculateDerivedData();
		/** Set the current inertia tensor. */
		void setInertiaTensor(const glm::mat3& inertiaTensor);
		/** Get the current inverted inertia tensor. */
		glm::mat3 getInverseTensor() const;

		/**
		 * Set the mass of this rigid body.
		 * Implicitly sets the inverse mass.
		 */
		void setMass(real mass);
		/** Get the mass of this rigid body. */
		real getMass() const;
		/**
		 * Set the inverse mass of this rigid body.
		 * Implicitly sets the mass.
		 * \param inverseMass An inverse mass of zero equals a rigid body
		 * with infinite mass.
		 */
		void setInverseMass(real inverseMass);
		/** Get the inverse mass */
		real getInverseMass() const;
		/** Check if this rigid body has infinite mass */
		bool hasFiniteMass() const;

		/* Force and torque accumulator access */
		glm::vec3 getForceAccumulated() const;
		glm::vec3 getTorqueAccumulated() const;

		/** Set the position of this rigid body. */
		void setCenterOfMass(const glm::vec3& centerOfMass);
		/** Set the position of this rigid body. */
		void setCenterOfMass(real x, real y, real z);
		/** Get the current position. */
		glm::vec3 getCenterOfMass() const;

		void setOrientation(const glm::quat& orientation);
		void setOrientation(real r, real i, real j, real k);
		glm::quat getOrientation() const;

		/** Set the current velocity. */
		void setVelocity(const glm::vec3& velocity);
		/** Set the current velocity. */
		void setVelocity(real x, real y, real z);
		/** Get the current velocity. */
		glm::vec3 getVelocity() const;

		/** Set the current acceleration. */
		void setAcceleration(const glm::vec3& acceleration);
		/** Set the current acceleration. */
		void setAcceleration(real x, real y, real z);
		/** Get the current acceleration. */
		glm::vec3 getAcceleration() const;

		/** Set the linear damping factor. */
		void setLinearDamping(real linearDamping);
		/** Get the linear damping factor. */
		real getLinearDamping() const;
		/** Get the angular damping factor. */
		void setAngularDamping(real angularDamping);
		/** Get the angular damping factor. */
		real getAngularDamping() const;

		void setRotation(const glm::vec3& rotation);
		void setRotation(real x, real y, real z);
		glm::vec3 getRotation() const;

		/** Get the current transformation. */
		glm::mat4 getTransformationMatrix() const;
		void getInverseInertiaTensorWorld(glm::mat3* inverseInertiaTensorWorld) const;

		void addVelocity(const glm::vec3& deltaVelocity);
		void addRotation(const glm::vec3& deltaRotation);

		/** Check if this rigid body is being simulated. */
		bool isAwake() const;
		/** Start or stop simulating this rigid body. */
		void setAwake(bool awake);

		/** Set the physics material. */
		void setPhysicsMaterial(PhysicsMaterial* material);
		/** 
		 * \brief Get the current physics material.
		 * \return The current physics material if existent, nullptr otherwise.	 
		 */
		PhysicsMaterial* getPhysicsMaterial() const;


		/** L�schen aller aufsummierten Kr�fte und Drehmomente. */
		void clearAccumulators();              
		/** 
		 * Hinzuf�gen einer Kraft in Weltkoordinaten. Die Kraft muss
		 * am Schwerpunkt angreifen. D'Allembert Prinzip.
		 */
		void addForce(const glm::vec3 & force); 
		/** 
		 * Hinzuf�gen einer Kraft in Weltkoordinaten. Die Kraft wirkt
		 * in einem Punkt in Weltkoordinaten. D'Allembert Prinzip.
		 * Kraft kann auch Drehmoment bewirken.
		 */
		void addForceAtPoint(const glm::vec3 & force, const glm::vec3 & point);
		/**
		 * Hinzuf�gen einer Kraft in Weltkoordinaten. Die Kraft wirkt 
		 * in einem Punkt in lokalen K�rperkoordinaten. D'Allembert Prinzip.
		 */
		void addForceAtBodyPoint(const glm::vec3 & force, const glm::vec3 & point);
		/** Hinzuf�gen eines Drehmoments. D'Allembert Prinzip. */
		void addTorque(const glm::vec3 & torque);

		glm::vec3 getPointInLocalSpace(const glm::vec3 &point) const;
		glm::vec3 getPointInWorldSpace(const glm::vec3 &point) const;
		glm::vec3 getDirectionInLocalSpace(const glm::vec3 &direction) const;
		glm::vec3 getDirectionInWorldSpace(const glm::vec3 &direction) const;

		/** Bestimmung des neuen Ortes f�r das Teilchen. */
		virtual void integrate(real duration);

	protected:
		PhysicsMaterial* m_physicsMaterial{};
		CollisionMask m_collisionMask;

		real m_mass;
		real m_inverseMass{};
		
		real m_linearDamping{};
		real m_angularDamping{};

		/*glm::vec3 m_centerOfMass;
		glm::quat m_orientation;*/
		
		glm::vec3 m_velocity;
		glm::vec3 m_acceleration;
		glm::vec3 m_lastFrameAcceleration; // Beschleunigung im letzten Frame ???
		glm::vec3 m_rotation;

		glm::mat4 m_transformationMatrix;
		glm::mat3 m_inverseInertiaTensor;
		glm::mat3 m_inverseInertiaTensorWorld;

		/* Accumulators */
		glm::vec3 m_forceAccumulated;
		glm::vec3 m_torqueAccumulated;
		bool m_awake = false;

		static void calculateTransformationMatrix(glm::mat4& transformationMatrix,
												  const glm::vec3& position,
												  const glm::mat3& orientation);

		static void transformInertiaTensor(glm::mat3& iitWorld,
										   const glm::mat3& iit,
										   const glm::mat4& rotMat);
	};
}

 