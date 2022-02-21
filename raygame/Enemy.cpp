#include "Enemy.h"
#include "SpriteComponent.h";
#include "Transform2D.h"
#include "SeekComponent.h"


Enemy::Enemy(float x, float y, const char* name, Actor* target) : Actor::Actor(x, y, name)
{
	
}

void Enemy::start()
{
	Actor::start();
	m_spriteComp = dynamic_cast<SpriteComponent*>(addComponent(new SpriteComponent("Images/enemy.png")));
	m_seekComp = dynamic_cast<SeekComponent*>(addComponent(new SeekComponent()));
	m_seekComp->setTarget(getTarget());
}

void Enemy::update(float deltaTime)
{
	Actor::update(deltaTime);
}
