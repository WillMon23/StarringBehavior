#include "Enemy.h"
#include "SpriteComponent.h";
#include "SeekComponent.h";
#include "MoveComponent.h"
#include "RotateComponent.h"
#include "FleeComponent.h"


Enemy::Enemy(float x, float y, const char* name, Actor* target) : Actor::Actor(x, y, name)
{
	m_target = target;
}

void Enemy::start()
{
	Actor::start();
	m_spriteComp = addComponent<SpriteComponent>();
	m_spriteComp->setPath("Images/enemy.png");
	

	m_seekComp = addComponent<SeekComponent>();
	m_seekComp->setTarget(getTarget());
	m_seekComp->setForce(20.0f);

	/*m_fleeComp = addComponent<FleeComponent>();
	m_fleeComp->setTarget(getTarget());*/

	//m_rotateComp = addComponent<RotateComponent>();
	
	m_moveComp = addComponent<MoveComponent>();
	m_moveComp->setVelocity({ 1,0 });
	m_moveComp->setMaxSpeed(100.0f);
}

void Enemy::update(float deltaTime)
{
	Actor::update(deltaTime);
}
