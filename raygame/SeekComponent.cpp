#include "SeekComponent.h"
#include "Actor.h"
#include "Transform2D.h"
#include <Matrix3.h>
#include <iostream>


void SeekComponent::start()
{
	m_maxSpeed = 100;
	m_velocity = { 1, 0 };
	m_maxVelocity = { 10,10 };
}

void SeekComponent::update(float deltaTime)
{
	//Sets the owener position to this veriable
	MathLibrary::Vector2 position = getOwner()->getTransform()->getWorldPosition();
	//Sets max speed for easy access 
	setMaxSpeed(300.0f);

	//Tries to creat a desired velocity bey getiing the targets curent position and subtracting that by 
	m_desiredVelocity = (getTarget()->getTransform()->getWorldPosition() - position).getNormalized();

	m_desiredVelocity = m_desiredVelocity * getMaxSpeed();

	MathLibrary::Vector2 steeringForce = m_desiredVelocity - m_velocity ;

	m_velocity = m_velocity + steeringForce * deltaTime * m_maxSpeed;
	
	position = position + m_velocity * deltaTime;


	std::cout << "X. " << position.x << std::endl;

	std::cout << "Y. " << position.y << std::endl;


	getOwner()->getTransform()->setWorldPostion(position);
}
 