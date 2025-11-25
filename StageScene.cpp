#include "StageScene.h"
#include <Novice.h>

void StageScene::Initialize() {
	enmyResporn = 120;
	isAlive = 1;
	radiusEnemy = 15;
	enemyPosX = 640;
	enemyPosY = 20;
	enemySpeedX = 3;

	preyerPosX = 640;
	preyerPosY = 360;
	preyerSpeedX = 5;
	preyerSpeedY = 5;
	heightWeight = 20;

	bulletPosX = 0;
	bulletPosY = 0;
	isBullet = 0;

}

void StageScene::Update(char* keys, char* preKeys) {

	if (keys[DIK_W]) {

		preyerPosY = preyerPosY - preyerSpeedY;
	}
	if (keys[DIK_A]) {

		preyerPosX = preyerPosX - preyerSpeedX;
	}
	if (keys[DIK_S]) {

		preyerPosY = preyerPosY + preyerSpeedY;
	}
	if (keys[DIK_D]) {

		preyerPosX = preyerPosX + preyerSpeedX;
	}
	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
		isBullet = 1;
	}

	/// ↓更新処理ここから
	// 画面外不可
	if (preyerPosX > 1280 - heightWeight) {
		preyerPosX = 1280 - heightWeight;
	}
	if (preyerPosY > 720 - heightWeight) {
		preyerPosY = 720 - heightWeight;
	}
	if (preyerPosX < 0 + heightWeight) {
		preyerPosX = 0 + heightWeight;
	}
	if (preyerPosY < 0 + heightWeight) {
		preyerPosY = 0 + heightWeight;
	}
	// 判定
	float diffrence_e2b_X = (bulletPosX - enemyPosX);
	float diffrence_e2b_Y = (bulletPosY - enemyPosY);
	float diffrence_e2b = diffrence_e2b_X * diffrence_e2b_X + diffrence_e2b_Y * diffrence_e2b_Y;
	float e2b_Radius = radiusEnemy + 10;
	if (e2b_Radius * e2b_Radius >= diffrence_e2b) {
		isAlive = 0;
		sceneNo = CLEAR;
	}

	// 敵フラグ
	if (isAlive == 0) {
		enmyResporn = enmyResporn - 1;
	}
	if (enmyResporn == 0) {
		isAlive = 1;
	}
	// 玉座標あわせ
	if (isBullet == 0) {
		bulletPosY = preyerPosY;
		bulletPosX = preyerPosX + heightWeight / 2.0f;
	}

	///
	/// ↑更新処理ここまで
	///

	///
	/// ↓描画処理ここから
	///

	if (isAlive == 1) {
		enmyResporn = 120;
		enemyPosX = enemyPosX + enemySpeedX;

		if (enemyPosX > 1280 - radiusEnemy) {
			enemySpeedX = -enemySpeedX;
		}
		if (enemyPosX < 0 + radiusEnemy) {
			enemySpeedX = -enemySpeedX;
		}
	}

	if (isBullet == 1) {

		bulletPosY = bulletPosY - 20;
	}

	if (bulletPosY <= -10) {
		isBullet = 0;
	}
}

void StageScene::Draw() {
	if (isAlive == 1) {
		Novice::DrawEllipse(int(enemyPosX), int(enemyPosY), int(radiusEnemy), int(radiusEnemy), 0.0f, 0xffffffff, kFillModeSolid);
	}
	if (isBullet == 1) {
		float bulletPosXLeft = bulletPosX - 8;
		float bulletPosXRight = bulletPosX + 8;
		float bulletPosYBottom = bulletPosY + 10;
		float bulletPosYUp = bulletPosY - 8;
		Novice::DrawTriangle(int(bulletPosX), int(bulletPosYUp), int(bulletPosXLeft), int(bulletPosYBottom), int(bulletPosXRight), int(bulletPosYBottom), 0Xff0000ff, kFillModeSolid);
	}
	Novice::ScreenPrintf(0, 0, "Curernt Scene : Stage");
	Novice::ScreenPrintf(0, 30, "Push Space : Next Scene");
	Novice::DrawBox(int(preyerPosX), int(preyerPosY), int(heightWeight), int(heightWeight), 0.0f, 0xffffffff, kFillModeSolid);
}