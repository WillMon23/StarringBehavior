#include "MainScene.h"
#include "SpriteComponent.h"
#include "MoveComponent.h"
#include "WanderComponent.h"
#include "StateMachine.h"
#include "SeekComponent.h"
#include "StateMachine.h"
#include "Transform2D.h"
#include "Player.h"
#include "Enemy.h"
#include "Agent.h"

void MainScene::start()
{
	Player* player = new Player(50, 50, "Player");
	player->getTransform()->setScale({ 50,50 });

	Enemy* enemy = new Enemy(300, 300, "enemy", player);
	enemy->getTransform()->setScale({ 50,50 });

	Agent* agent = new Agent();
	agent->getTransform()->setScale({ 50,50 });
	agent->setMaxForce(500.0f);
	agent->addComponent(new SpriteComponent("Images/enemy.png"));

	WanderComponent* wanderComp = new WanderComponent(1000, 200, 50);
	agent->addComponent(wanderComp);

	SeekComponent* seekComp = new SeekComponent();
	seekComp->setSteeringForce(50);
	seekComp->setTarget(player);
	agent->addComponent(seekComp);

	agent->addComponent<StateMachineComponent>();
	
	addItem(player);
	addItem(enemy);
	addItem(agent);
}
