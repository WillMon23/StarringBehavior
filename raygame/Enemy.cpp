#include "Enemy.h"
#include "SpriteComponent.h";
#include "SeekComponent.h";
#include "MoveComponent.h"
#include "RotateComponent.h"


Enemy::Enemy(float x, float y, const char* name, Actor* target) : Actor::Actor(x, y, name)
{
	m_target = target;
}

void Enemy::start()
{
	Actor::start();
	m_spriteComp = dynamic_cast addComponent<SpriteComponent>();
	

	m_seekComp = addComponent<SeekComponent>();
	m_seekComp->setTarget(getTarget());

	m_rotateComp = addComponent<RotateComponent>();
	m_moveComp = addComponent<MoveComponent>();

	m_moveComp->setVelocity({ 0,-1 });
	m_moveComp->setMaxSpeed(100);
}

void Enemy::update(float deltaTime)
{
	Actor::update(deltaTime);
}
