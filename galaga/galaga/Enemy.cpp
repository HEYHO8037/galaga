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
		total[i].x = mapX;
		total[i].y = mapY;

		mapX += 4;
	}

}


void Enemy::ShowEnemy(int map[40][20])
{
	for (int i = 0; i < enemycount; i++)
	{
		if (total[i].check == false)
		{
			for (int k = 0; k < 2; k++)
			{
				for (int j = 0; j < 3; j++)
				{
					map[total[i].y + k][total[i].x + j] += total[i].member[k][j];
				}
			}
		}
	}

}


void Enemy::MoveDeleteAllEnemy(int map[40][20])
{	
	for (int i = 0; i < enemycount; i++)
	{
		for (int k = 0; k < 2; k++)
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
		if (total[i].check == false)
		{
			if (total[enemycount - 1].x < 19)
			{
				total[i].x++;
			}
			else
			{
				total[i].x;
			}

			for (int k = 0; k < 2; k++)
			{
				for (int j = 0; j < 3; j++)
				{
					map[total[i].y + k][total[i].x + j] += total[i].member[k][j];
				}
			}
		}
	}
}

void Enemy::MoveLeftEnemy(int map[40][20])
{
	for (int i = 0; i < enemycount; i++)
	{
		if (total[i].check == false)
		{
			if (total[0].x > 0)
			{
				total[i].x--;
			}
			else
			{
				total[i].x;
			}

			for (int k = 0; k < 2; k++)
			{
				for (int j = 0; j < 3; j++)
				{
					map[total[i].y + k][total[i].x + j] += total[i].member[k][j];
				}
			}
		}
	}
}

void Enemy::HitCheckEnemy(int map[40][20])
{
	
	for (int i = 0; i < enemycount; i++)
	{
		if (total[i].check == false)
		{
			for (int k = 0; k < 2; k++)
			{
				for (int j = 0; j < 3; j++)
				{
					total[i].member[k][j] = map[total[i].y + k][total[i].x + j];
				}
			}
		}
	}
}

void Enemy::DestroyEnemy(int map[40][20])
{

	for (int i = 0; i < enemycount; i++)
	{
		for (int k = 0; k < 2; k++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (total[i].member[k][j] > 1)
				{
					total[i].check = true;
				}
			}
		}
	}

	for (int m = 0; m < enemycount; m++)
	{
		if (total[m].check == true)
		{
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					map[total[m].y + i][total[m].x + j] = 0;
				}
			}
		}
	}
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
	EnemyMember* save = total + (enemycount - 1);

	if (shotCount == 0 && enemycount != 0)
	{
		for (int i = 0; i < 4; i++)
		{
			InitBullet(0, save->x + 1, save->y + 2);
			save -= 1;
		}
	}
	else if (shotCount != 0 && enemycount != 0)
	{
		for (int i = 0; i < shotCount; i++)
		{
			InitBullet(0, save->x + 1, save->y + 2);
			save -= 1;
		}
	}

	showBullet(map);

}

void  Enemy::bulletMove(int map[40][20])
{
	MoveBullet(map);
}

void  Enemy::bulletCheck(int posX, int posY, int map[40][20])
{
	CheckBullet(posX, posY, map);
}

void  Enemy::bulletDestroy(int map[40][20])
{
	Destroy(map);
}

void  Enemy::bulletRelease()
{
	Release();
}
