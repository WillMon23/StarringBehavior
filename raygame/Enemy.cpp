#include "Enemy.h"
#include "SpriteComponent.h";
#include "SeekComponent.h"


Enemy::Enemy(float x, float y, const char* name, Actor* target) : Actor::Actor(x, y, name)
{
	m_target = target;
}

void Enemy::start()
{
	Actor::start();
	m_spriteComp = dynamic_cast<SpriteComponent*>(addComponent(new SpriteComponent("Images/enemy.png")));
	m_seekComp = dynamic_cast<SeekComponent*>(addComponent(new SeekComponent(getTarget())));
}

void Enemy::update(float deltaTime)
{
	Actor::update(deltaTime);
}
