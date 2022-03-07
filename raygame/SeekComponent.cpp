#include "SeekComponent.h"
#include "Actor.h"
#include <Vector2.h>
#include "Agent.h"
#include "MoveComponent.h"
#include <Matrix3.h>
#include <iostream>


void SeekComponent::start()
{
	m_force = 100;
	m_velocity = { 1, 0 };
	m_maxVelocity = { 10,10 };
}

void SeekComponent::update(float deltaTime)
{
	//Sets the owener position to this veriable
	MathLibrary::Vector2 position = getOwner()->getTransform()->getWorldPosition();
	//Sets max speed for easy access 
	setForce(300.0f);

	m_velocity = getOwner()->getComponent<MoveComponent>()->getVelocity().getNormalized();

	//Tries to creat a desired velocity bey getiing the targets curent position and subtracting that by 
	m_desiredVelocity = (getTarget()->getTransform()->getWorldPosition() - position).getNormalized();

	//After getiing the desired velocity multiply that velocty by a force 
	m_desiredVelocity = m_desiredVelocity * getForce();

	//
	MathLibrary::Vector2 steeringForce = m_desiredVelocity + m_velocity ;

	m_velocity = m_velocity + steeringForce * deltaTime * getForce();
	
	position = position + m_velocity * deltaTime;


	std::cout << "X. " << position.x << std::endl;

	std::cout << "Y. " << position.y << std::endl;


	getOwner()->getTransform()->setWorldPostion(position);
}

MathLibrary::Vector2 SeekComponent::calculateForce()
{
	if (!getTarget())
		return { 0,0 };

	MathLibrary::Vector2 directionToTarget = getTarget()->getTransform()->getWorldPosition()
		- getOwner()->getTransform()->getWorldPosition();

	MathLibrary::Vector2 desiredVelocity = directionToTarget.getNormalized() * getSteeringForce();
	MathLibrary::Vector2 seekForce = desiredVelocity - getAgent()->getMoveMoveComponent()->getVelocity();
	return seekForce;
 