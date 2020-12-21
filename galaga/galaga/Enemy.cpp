#include "Enemy.h"

void Enemy::InitEnemy(int enemynumber, int map[40][20])
{
	enemycount = enemynumber;
	for (int i = 0; i < enemycount; i++)
	{
		if (i % 4 == 0 && i != 0)
		{
			mapY += 3;
			mapX = 2;
		}

		EnemyMember* name = new EnemyMember;
		name->x = mapX;
		name->y = mapY;
		
		if (i == 0)
		{
			name->ebMember = nullptr;
			name->efMember = nullptr;
		}
		else
		{
			name->efMember = eSave;
			name->efMember->ebMember = eSave;
		}


		for (int i = 0; i < 3; i++)
		{
			for (int k = 0; k < 3; k++)
			{
				map[name->y + i][name->x + k] += name->member[i][k];
			}
		}
		mapX += 4;
		eSave = name;

	}
	mapX -= 4;

}

void Enemy::MoveDeleteEnemy(int map[40][20])
{	
	EnemyMember* mdEnemy = eSave;
	for (int count = 0; count < enemycount; count++)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int k = 0; k < 3; k++)
			{
				map[mdEnemy->y + i][mdEnemy->x + k] = 0;
			}
		}
		mdEnemy = mdEnemy->efMember;
	}
}

//void Enemy::MoveRightEnemy(int map[40][20])
//{
//	if (maxX < 16)
//	{
//		MoveDeleteEnemy(map);
//		mapX++;
//		InitEnemy(enemycount, map);
//	}
//	else
//	{
//		MoveDeleteEnemy(map);
//		InitEnemy(enemycount, map);
//	}
//}
//
//void Enemy::MoveLeftEnemy(int map[40][20])
//{
//	if (maxX > 13)
//	{
//		MoveDeleteEnemy(map);
//		mapX--;
//		InitEnemy(enemycount, map);
//	}
//	else
//	{
//		MoveDeleteEnemy(map);
//		InitEnemy(enemycount, map);
//	}
//}