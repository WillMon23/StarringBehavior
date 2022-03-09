#include "Agent.h"
#include "MoveComponent.h"

void Agent::start()
{
	Actor::start();
	m_moveComponent = addComponent<MoveComponent>();
	m_moveComponent->setMaxSpeed(5);
	m_moveComponent->setUpdateFacing(true);
}

void Agent::update(float deltaTime)
{
	Actor::update(deltaTime);
	//Get all the force being applied from steerin behaviors a
	for (int i = 0; i < m_steeringComponent.getLength(); i++)
	{
		m_force = m_force + m_steeringComponent[i]->calculateForce();
	}

	//Clamp force if it exceeds the maximum scales 
	if (m_force.getMagnitude() > getMaxForce())
	{
		m_force = getForce().getNormalized() * getMaxForce();
	}

	//Apply force to velocity
	getMoveComponent()->setVelocity(getMoveComponent()->getVelocity() + getForce() * deltaTime);
}

void Agent::onAddComponent(Component* componet)
{
	SteeringComponent* steeringComponent = dynamic_cast<SteeringComponent*>(componet);
	if (steeringComponent)
		m_steeringComponent.addItem(steeringComponent);
}
