#include "Player.h"
#include "InputComponent.h"
#include "RotateComponent.h"
#include "MoveComponent.h"
#include "SpriteComponent.h"

void Player::start()
{
	Actor::start();

	m_inputComponent = addComponent<InputComponent>();

	m_moveComponent = addComponent<MoveComponent>();

	m_moveComponent->setMaxSpeed(10);

	m_spriteComponent = addComponent<SpriteComponent>();
	m_spriteComponent->setPath("Images/player.png");
	addComponent<RotateComponent>();

	//Set spawn point
	//Set move speed
	//Set position clamps
}

void Player::update(float deltaTime)
{

	MathLibrary::Vector2 moveDirection = m_inputComponent->getMoveAxis();

	m_moveComponent->setVelocity(moveDirection * 200);
	Actor::update(deltaTime);
}
