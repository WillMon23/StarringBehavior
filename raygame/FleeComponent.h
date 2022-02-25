#pragma once
#include "Transform2D.h"
#include "Actor.h"
#include "Component.h"
#include <iostream>

class FleeComponent : public Component{
public:
	FleeComponent() {};
	~FleeComponent() {};

	void update(float deltaTime) override;

	Actor* getTarget() { return m_target; };
	float  getForce() { return m_force; };

	void setTarget(Actor* target) { m_target = target; };
	void setForce(float force) { m_force = force; };

private:
	Actor* m_target;
	MathLibrary::Vector2 m_velocity;
	MathLibrary::Vector2 m_desiredVelocity;
	float m_force;
};

void FleeComponent::update(float deltaTime) {

	//Sets the owener position to this veriable
	MathLibrary::Vector2 position = getOwner()->getTransform()->getWorldPosition();
	//Sets max speed for easy access 
	setForce(300.0f);

	//Tries to creat a desired velocity bey getiing the targets curent position and subtracting that by 
	m_desiredVelocity = (position - getTarget()->getTransform()->getWorldPosition()).getNormalized();

	//After getiing the desired velocity multiply that velocty by a force 
	m_desiredVelocity = m_desiredVelocity * getForce();

	//
	MathLibrary::Vector2 steeringForce = m_desiredVelocity - m_velocity;

	std::cout << "X. " << steeringForce.x << std::endl;

	std::cout << "Y. " << steeringForce.y << std::endl;


	m_velocity = m_velocity + steeringForce * deltaTime * getForce();

	position = position + m_velocity * deltaTime;


	std::cout << "X. " << position.x << std::endl;

	std::cout << "Y. " << position.y << std::endl;


	getOwner()->getTransform()->setWorldPostion(position);
}