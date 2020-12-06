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
	int mapY = 36;
	int mapX = 2;
	int enemycount = 0;
	int random = rand() % 2;

public:
	void InitEnemy(EnemyMember* name, int map[40][20]);
	void MoveEnemy(EnemyMember* name, int map[40][20]);
	void MoveDeleteEnemy(EnemyMember* name, int map[40][20]);
};