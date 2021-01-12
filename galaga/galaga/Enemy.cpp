#include "Enemy.h"
using namespace std;

void Enemy::InitEnemy(int enemynumber)
{
	mapX = 2;
	mapY = 2;

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


void Enemy::ShowAllEnemy(int map[40][20])
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

void Enemy::ShowEnemy(int eneNum, int map[40][20])
{
	if (total[eneNum].check == false)
	{
		for (int k = 0; k < 2; k++)
		{
			for (int j = 0; j < 3; j++)
			{
				map[total[eneNum].y + k][total[eneNum].x + j] += total[eneNum].member[k][j];
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

void Enemy::MoveDeleteEnemy(int num, int eneNum, int map[40][20])
{
	if (num == 0 && total[eneNum].check == false)
	{
		total[eneNum].x--;
		for (int i = 0; i < 2; i++)
		{
			for (int k = 0; k < 3; k++)
			{
				map[total[eneNum].y + i][total[eneNum].x + k] = 0;
			}
		}
		total[eneNum].x++;
	}
	if (num == 1 && total[eneNum].check == false)
	{
		total[eneNum].x++;
		for (int i = 0; i < 2; i++)
		{
			for (int k = 0; k < 3; k++)
			{
				map[total[eneNum].y + i][total[eneNum].x + k] = 0;
			}
		}
		total[eneNum].x--;
	}
	if (num == 2)
	{
		for (int i = 0; i < 2; i++)
		{
			for (int k = 0; k < 3; k++)
			{
				map[total[eneNum].y + i][total[eneNum].x + k] = 0;
			}
		}
	}
	
}


void Enemy::MoveRightEnemy(int map[40][20])
{
	if (total[enemycount-1].x+2 < 18)
	{
		for (int i = 0; i < enemycount; i++)
		{
			total[i].x++;
			MoveDeleteEnemy(0, i, map);
			ShowEnemy(i, map);
		}
	}
}

void Enemy::MoveLeftEnemy(int map[40][20])
{
	if (total[0].x > 1)
	{
		for (int i = 0; i < enemycount; i++)
		{
			total[i].x--;
			MoveDeleteEnemy(1, i, map);
			ShowEnemy(i, map);
		}
	}
}

void Enemy::MoveRandEnemy(int map[40][20])
{
	random_device rd;

	mt19937_64 gen(rd());
	uniform_int_distribution<int> dis(0, 2);

	if (dis(gen) == 0)
	{
		MoveLeftEnemy(map);
	}
	else if (dis(gen) == 1)
	{
		MoveRightEnemy(map);
	}
	else
	{
		MoveDeleteAllEnemy(map);
		ShowAllEnemy(map);
	}
}



void Enemy::HitCheckEnemy(int map[40][20], int& score)
{
	mEnemycount = 0;
	score = 0;

	for (int i = 0; i < enemycount; i++)
	{
		if (total[i].hp == 0)
		{
			total[i].check = true;
			MoveDeleteEnemy(2, i, map);
		}
		if (total[i].check == false)
		{
			for (int k = 0; k < 2; k++)
			{
				for (int j = 0; j < 3; j++)
				{
					if (map[total[i].y + k][total[i].x + j] > 1)
					{
						total[i].hp--;
						MoveDeleteEnemy(2, i, map);
						ShowEnemy(i, map);
					}
				}
			}
		}

	}



	for (int i = 0; i < enemycount; i++)
	{
		if (total[i].check == false)
		{
			mEnemycount++;
		}
		else if (total[i].check == true)
		{
			score += 100;
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


void Enemy::RandBullet(int map[40][20])
{
	random_device rd;

	mt19937_64 gen(rd());
	uniform_int_distribution<int> dis(0, 50);

	if (dis(gen) == 0)
	{
		bulletInit(map);
	}
}


void Enemy::bulletInit(int map[40][20])
{
	int shotCount = mEnemycount % 4;
	int count = 0;
	EnemyMember* save = total + (enemycount - 1);


	if (shotCount == 0 && enemycount != 0)
	{
		for (int k = 0; k < enemycount; k++)
		{
			if (count != 4)
			{
				if (save->check == false)
				{
					InitBullet(0, save->x + 1, save->y + 2);
					save -= 1;
					count++;
				}
				else if (save->check == true)
				{
					save -= 1;
				}
			}
			else if (count == 4)
			{
				break;
			}
		}
	}
	else if (shotCount != 0 && enemycount != 0)
	{
		for (int k = 0; k < enemycount; k++)
		{
			if (count != shotCount)
			{
				if (save->check == false)
				{
					InitBullet(0, save->x + 1, save->y + 2);
					save -= 1;
					count++;
				}
				else if (save->check == true)
				{
					save -= 1;
				}
			}
			else if (count == shotCount)
			{
				break;
			}
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
