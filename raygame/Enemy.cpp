#include "Enemy.h"
#include "SpriteComponent.h";
#include "WanderComponent.h"
#include "SeekComponent.h";
#include "DecisionComponent.h"
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
	Agent::start();

	IdleDecision* idle = new IdleDecision();
	WanderDecision* wander = new WanderDecision();
	SeekDecision* seek = new SeekDecision();

	isAgressiveDecision* agressive = new isAgressiveDecision(idle, wander);
	InrangeDecision* inRange =  new InrangeDecision(agressive, seek);

	addComponent(new DecisionComponent(inRange));

	getTransform()->setScale({ 50,50 });
	addComponent(new SpriteComponent("Images/enemy.png"));

	WanderComponent* wanderComponent = new WanderComponent(100, 100, 100);
	addComponent(wanderComponent);

	SeekComponent* seekComp = new SeekComponent();
	seekComp->setSteeringForce(10);
	seekComp->setTarget(getTarget());
	addComponent(seekComp);
}

void Enemy::update(float deltaTime)
{
	Agent::update(deltaTime);
}

bool Enemy::getTargetInSight()
{
	float distance = (m_target->getTransform()->getWorldPosition() - getTransform()->getWorldPosition()).getMagnitude();

	MathLibrary::Vector2 directVector = (m_target->getTransform()->getWorldPosition() - getTransform()->getWorldPosition()).getNormalized();
	return distance <= 10 && acos(MathLibrary::Vector2::dotProduct(directVector, getTransform()->getForward())) < 1;
}
