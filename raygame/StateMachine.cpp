#include "StateMachine.h"
#include "SeekComponent.h"
#include "WanderComponent.h"
#include "Actor.h"
#include "Transform2D.h"

void StateMachineComponent::start()
{
	Component::start();
	m_seekComp = getOwner()->getComponent< SeekComponent>();
	m_seekForce = m_seekComp->getSteeringForce();

	m_wanderComp = getOwner()->getComponent< WanderComponent >();
	m_wanderForce = m_wanderComp->getSteeringForce();

	m_currentState = IDLE;
}

void StateMachineComponent::update(float deltaTime)
{
	bool targetInRange = false;

	MathLibrary::Vector2 targetPos = m_seekComp->getTarget()->getTransform()->getWorldPosition();

	MathLibrary::Vector2 ownerPos = getOwner()->getTransform()->getWorldPosition();
	float distanceFromTarget = (targetPos - ownerPos).getMagnitude();

	bool targetInRAnge = distanceFromTarget <= m_seekRange;

	switch (m_currentState)
	{
	case IDLE:
		m_seekComp->setSteeringForce(0);
		m_wanderComp->setSteeringForce(0);

		if (targetInRange)
			setCurrentState(SEEK);
		break;

	case WANDER:
		m_seekComp->setSteeringForce(0);
		m_wanderComp->setSteeringForce(m_wanderForce);
		if (targetInRange)
			setCurrentState(SEEK);
		break;

	case SEEK:
		m_seekComp->setSteeringForce(m_seekForce);
		m_wanderComp->setSteeringForce(0);
		if (!targetInRange)
			setCurrentState(SEEK);
		break;
	}
}
