//#pragma once
#include "IScene.h"
#include <Novice.h>

class StageScene : public IScene {

public:
	void Initialize() override;
	void Update(char* keys, char* preKeys) override;
	void Draw() override;
	int enmyResporn = 120;
	int isAlive = 1;
	float radiusEnemy = 15;
	float enemyPosX = 640;
	float enemyPosY = 20;
	float enemySpeedX = 3;

	// 自機
	float preyerPosX = 640;
	float preyerPosY = 360;
	float preyerSpeedX = 5;
	float preyerSpeedY = 5;
	float heightWeight = 20;
	// 玉
	float bulletPosX = 0;
	float bulletPosY = 0;
	float isBullet = 0;
};