#include "MainScene.h"
#include "SpriteComponent.h"
#include "MoveComponent.h"
#include "WanderComponent.h"
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
	agent->setMaxForce(200.0f);
	agent->addComponent(new SpriteComponent("Images/enemy.png"));
	WanderComponent* comp = new WanderComponent(1000, 200, 50);
	agent->addComponent(comp);
	
	addItem(player);
	addItem(enemy);
	addItem(agent);
}
