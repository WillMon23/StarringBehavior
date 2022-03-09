#include "RotateComponent.h"
#include "Transform2D.h"
#include "Actor.h"
void RotateComponent::update(float deltaTime)
{
	getOwner()->getTransform()->rotate(getOwner()->getTransform()->getForward().getMagnitude());
}
