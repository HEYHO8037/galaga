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

		emember = &total[i];

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


void Enemy::MoveRightEnemy(int map[40][20])
{
	for (int i = 0; i < enemycount; i++)
	{
		if(total[enemycount].x < 17)
		{
			total[i].x++;
		}
		else
		{
			total[i].x;
		}

		for (int k = 0; k < 3; k++)
		{
			for (int j = 0; j < 3; j++)
			{
				map[total[i].y + k][total[i].x + j] += total[i].member[k][j];
			}
		}
	}
}

void Enemy::MoveLeftEnemy(int map[40][20])
{
	for (int i = 0; i < enemycount; i++)
	{
		if (total[0].x > 0)
		{
			total[i].x--;
		}
		else
		{
			total[i].x;
		}

		for (int k = 0; k < 3; k++)
		{
			for (int j = 0; j < 3; j++)
			{
				map[total[i].y + k][total[i].x + j] += total[i].member[k][j];
			}
		}
	}
}

void Enemy::HitCheckEnemy(int map[40][20])
{
	for (int i = 0; i < enemycount; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			for (int j = 0; j < 3; j++)
			{
				total[i].member[k][j] = map[total[i].x + k][total[i].y + j];
			}
		}
	}
}

void Enemy::DestroyEnemy(int map[40][20])
{
	bool check = false;
	int desMember = 0;

	for (int i = 0; i < enemycount; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (total[i].member[k][j] > 1)
				{
					desMember = i;
					check = true;
					break;
				}
			}
			if (check)
			{
				break;
			}
		}
		if (check)
		{
			break;
		}
	}

	if (check)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				map[total[desMember].y + i][total[desMember].x + j] = 0;
			}
		}
	}

	delete [desMember]total;
}

void Enemy::ReleaseAllEnemy()
{
	delete[] total;
}

