#include "Player.h"
#include "InputComponent.h"
#include "MoveComponent.h"
#include "SpriteComponent.h"

void Player::start()
{
	Actor::start();

	m_inputComponent = new InputComponent();
	m_moveComponent = new MoveComponent();
	m_moveComponent->setMaxSpeed(10);
	m_spriteComponent = new SpriteComponent("Images/player.png");

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
