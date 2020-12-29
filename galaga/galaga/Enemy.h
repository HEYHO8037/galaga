#pragma once
#include <random>
class Enemy
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

		int x = 0;
		int y = 0;
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
};