#include "Enemy.h"

void Enemy::InitEnemy(EnemyMember* name, int map[40][20])
{
	name = new EnemyMember;
	for (int i = 0; i < 3; i++)
	{
		name->x = mapX;
		name->y = mapY;
		for (int k = 0; k < 3; k++)
		{
			map[mapY-i][mapX] += name->member[i][k];
		}
	}
	mapX += 4;
	enemycount++;

	if (enemycount % 3 == 0)
	{
		mapY -= 3;
	}
	
}

void Enemy::MoveDeleteEnemy(EnemyMember* name, int map[40][20])
{
	name->x = mapX;
	name->y = mapY;
	
	for (int i = 0; i < 3; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			map[mapY - i][mapX + k] = 0;
		}
	}

	
}

void Enemy::MoveEnemy(EnemyMember* name, int map[40][20])
{

	int movX = name->x;
	int movY = name->y;

	if (random % 2 == 0)
	{
		movX++;
		for (int i = 0; i < 3; i++)
		{
			for (int k = 0; k < 3; k++)
			{
				map[movY - i][movX + k] += name->member[i][k];
			}
		}
	}

	else if (random % 2 == 1)
	{
		movX--;
		for (int i = 0; i < 3; i++)
		{
			for (int k = 0; k < 3; k++)
			{
				map[movY - i][movX + k] += name->member[i][k];
			}
		}
	}
}