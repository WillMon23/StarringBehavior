#include "Agent.h"
#include "MoveComponent.h"

void Agent::start()
{
	m_moveComponent = addComponent<MoveComponent>();
}

void Agent::update(float deltaTime)
{
	//Get all the force being applied from steerin behaviors 
	for (int i = 0; i < m_steeringComponent.getLength(); i++)
	{
		m_force = m_force + m_steeringComponent[i]->calculateForce();
	}

	//Clamp force if it exceeds the maximum scales 
	if (m_force.getMagnitude() > getMaxForce())
	{
		m_force = m_force.getNormalized() * getMaxForce();
	}

	//Apply force to velocity
	getMoveMoveComponent()->setVelocity(getMoveMoveComponent()->getVelocity() + m_force * deltaTime);
}

void Agent::onAddComponent(Component* componet)
{
	SteeringComponent* steeringComponent = dynamic_cast<SteeringComponent*>(componet);
	if (steeringComponent)
		m_steeringComponent.addItem(steeringComponent);
}
