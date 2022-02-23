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
	m_spriteComp = dynamic_cast<SpriteComponent*>(addComponent(new SpriteComponent("Images/enemy.png")));
	m_seekComp = dynamic_cast<SeekComponent*>(addComponent(new SeekComponent(getTarget())));
	m_rotateComp = dynamic_cast<RotateComponent*>(addComponent(new RotateComponent()));
	/*m_moveComp = dynamic_cast<MoveComponent*>(addComponent(new MoveComponent()));
	m_moveComp->setVelocity({ 0,-1 });
	m_moveComp->setMaxSpeed(100);*/
}

void Enemy::update(float deltaTime)
{
	Actor::update(deltaTime);
}
