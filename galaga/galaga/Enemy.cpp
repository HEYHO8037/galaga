#include "Enemy.h"

void Enemy::InitEnemy(int enemynumber, int map[40][20])
{
	enemycount = enemynumber;
	for (int count = 0; count < enemynumber; count++)
	{
		EnemyMember name;
		if (count % 4 == 0)
		{
			maxY += 3;
			maxX = mapX;
		}

		if (count == 0)
		{
			maxX = mapX;
			maxY = mapY;
		}

		for (int i = 0; i < 3; i++)
		{
			for (int k = 0; k < 3; k++)
			{
				map[maxY + i][maxX + k] += name.member[i][k];
			}
		}
		maxX += 4;
	}
	maxX -= 4;
}

void Enemy::MoveDeleteEnemy(int map[40][20])
{	
	for (int count = 0; count < enemycount; count++)
	{
		if (count % 4 == 0 )
		{
			maxX = mapX;
			maxY += 3;
		}
		if (count == 0)
		{
			maxX = mapX;
			maxY = mapY;
		}

		for (int i = 0; i < 3; i++)
		{
			for (int k = 0; k < 3; k++)
			{
				map[maxY + i][maxX + k] = 0;
			}
		}
		maxX += 4;
	}
	maxX -= 4;
}

void Enemy::MoveRightEnemy(int map[40][20])
{
	if (maxX < 16)
	{
		MoveDeleteEnemy(map);
		mapX++;
		InitEnemy(enemycount, map);
	}
	else
	{
		MoveDeleteEnemy(map);
		InitEnemy(enemycount, map);
	}
}

void Enemy::MoveLeftEnemy(int map[40][20])
{
	if (maxX > 13)
	{
		MoveDeleteEnemy(map);
		mapX--;
		InitEnemy(enemycount, map);
	}
	else
	{
		MoveDeleteEnemy(map);
		InitEnemy(enemycount, map);
	}
}