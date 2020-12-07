#include "Enemy.h"

void Enemy::InitEnemy(int enemynumber, int map[40][20])
{
	for (enemycount; enemycount < enemynumber; enemycount++)
	{
		EnemyMember name;
		if (enemycount % 4 == 0)
		{
			maxY += 3;
		}

		if (enemycount == 0)
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
	
}

void Enemy::MoveDeleteEnemy(int map[40][20])
{	
	int count = 0;

	for (count; count < enemycount; count++)
	{
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
		if (enemycount % 4 == 0)
		{
			maxY += 3;
		}
	}

	
}

void Enemy::MoveEnemy(int map[40][20])
{


	for (int i=1; i<=enemycount; i++)
	{
		MoveDeleteEnemy(map);
		InitEnemy(enemycount, map);
	}



}