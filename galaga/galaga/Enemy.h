#pragma once
#include <random>
#include "Bullet.h"

static struct EnemyMember
{
	int member[2][3] =
	{
		{1,1,1},
		{0,1,0},
	};
	int hp = 3;

	bool check = false;
	int x = 0;
	int y = 0;
};

class Enemy : Bullet
{
public:
	EnemyMember* total;
	int enemycount = 0;
	int mEnemycount = 0;
protected:
	int mapY = 2;
	int mapX = 2;

public:
	void InitEnemy(int enemynumber);
	void ShowAllEnemy(int map[40][20]);
	void ShowEnemy(int eneNum, int map[40][20]);
	void MoveRightEnemy(int map[40][20]);
	void MoveLeftEnemy(int map[40][20]);
	void MoveDeleteAllEnemy(int map[40][20]);
	void MoveDeleteEnemy(int num, int eneNum, int map[40][20]);
	void HitCheckEnemy(int map[40][20]);
	void ReleaseAllEnemy();
	void MoveRandEnemy(int map[40][20]);

public:
	void RandBullet(int map[40][20]);
	void bulletCreate(int count);
	void bulletInit(int map[40][20]);
	void bulletMove(int map[40][20]);
	void bulletCheck(int posX, int posY, int map[40][20]);
	void bulletDestroy(int map[40][20]);
	void bulletRelease();
};