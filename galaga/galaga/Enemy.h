#pragma once
#include "import.h"

class Enemy
{
private:
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
	int maxY = 0;
	int maxX = 0;

	int mapY = 2;
	int mapX = 2;

	int enemycount = 0;
	int random = rand() % 2;

public:
	void InitEnemy(int enemynumber, int map[40][20]);
	void MoveRightEnemy(int map[40][20]);
	void MoveLeftEnemy(int map[40][20]);
	void MoveDeleteEnemy(int map[40][20]);
};