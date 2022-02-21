#include "MainScene.h"
#include "SpriteComponent.h"
#include "MoveComponent.h"
#include "Transform2D.h"
#include "Player.h"
#include "Enemy.h"

void MainScene::start()
{
	Player* player = new Player(50, 50, "Player");
	player->getTransform()->setScale({ 50,50 });

	Enemy* enemy = new Enemy(100, 100, "enemy", player);
	enemy->getTransform()->setScale({ 50,50 });
	
	addActor(player);
	addActor(enemy);
}
