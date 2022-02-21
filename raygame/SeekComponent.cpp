#include "SeekComponent.h"
#include "Actor.h"
#include "Transform2D.h"
#include <Matrix3.h>


void SeekComponent::update(float deltaTime)
{

	m_direction = /*getOwner()->getTransform()->getWorldPosition() + */getTarget()->getTransform()->getWorldPosition();

	getOwner()->getTransform()->setLocalPosition(m_direction);
}
