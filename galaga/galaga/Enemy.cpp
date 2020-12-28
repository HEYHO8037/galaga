#include "Enemy.h"

void Enemy::InitEnemy(int enemynumber)
{
	enemycount = enemynumber;
	total = new EnemyMember[enemycount];

	for (int i = 0; i < enemycount; i++)
	{
		EnemyMember* emember = new EnemyMember;
		if (i % 4 == 0 && i != 0)
		{
			mapY += 3;
			mapX = 2;
		}
		emember->x = mapX;
		emember->y = mapY;

		total[i].x = emember->x;
		total[i].y = emember->y;

		mapX += 4;
	}
	
	
}


void Enemy::ShowEnemy(int map[40][20])
{
	for (int i = 0; i < enemycount; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			for (int j = 0; j < 3; j++)
			{
				map[total[i].y + k][total[i].x + j] += total[i].member[k][j];
			}
		}
	}

}


void Enemy::MoveDeleteAllEnemy(int map[40][20])
{	
	for (int i = 0; i < enemycount; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			for (int j = 0; j < 3; j++)
			{
				map[total[i].y + k][total[i].x + j] = 0;
			}
		}
	}
}

void Enemy::MoveDeleteEnemy(EnemyMember* input, int map[40][20])
{

}

void Enemy::MoveRightEnemy(int map[40][20])
{

}

void Enemy::MoveLeftEnemy(int map[40][20])
{

}

void Enemy::HitEnemy(int map[40][20])
{

}

void Enemy::DestroyEnemy(int map[40][20])
{

}

void Enemy::ReleaseEnemy()
{

}

