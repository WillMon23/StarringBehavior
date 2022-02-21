#include "SeekComponent.h"
#include "Actor.h"
#include "Transform2D.h"
#include <Matrix3.h>


void SeekComponent::update(float deltaTime)
{
	MathLibrary::Vector2 newPosition = getOwner()->getTransform()->getWorldPosition() + getTarget()->getTransform()->getWorldPosition();
	newPosition.getNormalized();

	setMaxSpeed(20.0f);

	m_direction = newPosition * getMaxSpeed();

	MathLibrary::Vector2 seekForch = m_direction - getOwner()->getTransform()->getWorldPosition();

	m_velocity = m_velocity + (m_direction * deltaTime);

	getOwner()->getTransform()->setWorldPostion(getOwner()->getTransform()->getWorldPosition() + m_velocity * deltaTime);
}
 