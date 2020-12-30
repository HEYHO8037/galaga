#include "Enemy.h"

void Enemy::InitEnemy(int enemynumber)
{
	enemycount = enemynumber;
	total = new EnemyMember[enemycount];

	for (int i = 0; i < enemycount; i++)
	{
		if (i % 4 == 0 && i != 0)
		{
			mapY += 3;
			mapX = 2;
		}

		total[i].x = mapX;
		total[i].y = mapY;

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

void Enemy::bulletCreate(int count)
{
	Construct(count);
}


void Enemy::bulletInit(int map[40][20])
{
	int shotCount = enemycount % 4;

	if (shotCount == 0 && enemycount != 0)
	{
		for (int i = 0; i < 4; i++)
		{
			InitBullet(0, total[enemycount - i].x, total[enemycount - i].y, map);
		}
	}
	else if (shotCount != 0 && enemycount != 0)
	{
		for (int i = 0; i < shotCount; i++)
		{
			InitBullet(0, total[enemycount - i].x, total[enemycount - i].y, map);
		}
	}

}

void  Enemy::bulletMove(int map[40][20])
{
	MoveBullet(map);
}

void  Enemy::bulletCheck(int map[40][20])
{
	CheckBullet(map);
}

void  Enemy::bulletDestroy(int map[40][20])
{
	Destroy(map);
}

void  Enemy::bulletRelease()
{
	Release();
}
