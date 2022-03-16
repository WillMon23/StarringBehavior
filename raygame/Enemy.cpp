#include "Enemy.h"
#include "SpriteComponent.h";
#include "SeekComponent.h";
#include "MoveComponent.h"
#include "RotateComponent.h"
#include "FleeComponent.h"
#include "SeekDecision.h"
#include "InrangeDecision.h"
#include "WanderDecision.h"
#include "isAgressiveDecision.h"
#include "IdleDecision.h"
#include "Decision.h"


Enemy::Enemy(float x, float y, const char* name, Actor* target)
{
	m_target = target;
}

Enemy::Enemy(float x, float y, const char* name, float maxForce, float maxSpeed, Actor* target) :Agent::Agent(x, y, name, maxForce, maxSpeed)
{
	m_target = target;
}

void Enemy::start()
{
	Actor::start();

	IdleDecision* idle = new IdleDecision();
	WanderDecision* wander = new WanderDecision();
	SeekDecision* seek = new SeekDecision();

	isAgressiveDecision agressive = new isAgressiveDecision(idle, wander);
	InrangeDecision inRanget = InrangeDecision();
	addComponent<SpriteComponent>();
	getComponent<SpriteComponent>()->setPath("Images/enemy.png");
	

	m_seekComp = addComponent<SeekComponent>();
	m_seekComp->setTarget(getTarget());
	m_seekComp->setForce(20.0f);

	/*m_fleeComp = addComponent<FleeComponent>();
	m_fleeComp->setTarget(getTarget());*/

	m_rotateComp = addComponent<RotateComponent>();
	
	m_moveComp = addComponent<MoveComponent>();
	m_moveComp->setVelocity({ 1,0 });
	m_moveComp->setMaxSpeed(100.0f);
}

void Enemy::update(float deltaTime)
{
	Actor::update(deltaTime);
}

bool Enemy::getTargetInRange()
{
	float distance = m_target->getTransform()->getWorldPosition().getMagnitude();
	return distance <= 10;
}
