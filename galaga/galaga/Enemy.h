#pragma once
#include <random>
#include "Bullet.h"
class Enemy : Bullet
{
protected:
	struct EnemyMember
	{
		int member[3][3] =
		{
			{1,1,1},
			{0,1,0},
			{0,0,0}
		};
		int hp = 3;

		int x;
		int y;
	};

	EnemyMember* total;

	int mapY = 2;
	int mapX = 2;

	int enemycount = 0;
	int random = rand() % 2;

public:
	void InitEnemy(int enemynumber);
	void ShowEnemy(int map[40][20]);
	void MoveRightEnemy(int map[40][20]);
	void MoveLeftEnemy(int map[40][20]);
	void MoveDeleteAllEnemy(int map[40][20]);
	void HitCheckEnemy(int map[40][20]);
	void DestroyEnemy(int map[40][20]);
	void ReleaseAllEnemy();

public:
	void bulletCreate(int count);
	void bulletInit(int map[40][20]);
	void bulletMove(int map[40][20]);
	void bulletCheck(int map[40][20]);
	void bulletDestroy(int map[40][20]);
	void bulletRelease();
};