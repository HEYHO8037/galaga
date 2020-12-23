#include "Enemy.h"

void Enemy::InitEnemy(int enemynumber)
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

		mapX += 4;
		eSave = name;
	}
	
}


void Enemy::ShowEnemy(int map[40][20])
{
	EnemyMember* msEnemy = eSave;
	for (int i = 0; i < enemycount; i++)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int k = 0; k < 3; k++)
			{
				map[msEnemy->y + i][msEnemy->x + k] += msEnemy->member[i][k];
			}
		}
		msEnemy = msEnemy->efMember;
	}
}


void Enemy::MoveDeleteAllEnemy(int map[40][20])
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

void Enemy::MoveDeleteEnemy(EnemyMember* input, int map[40][20])
{
	for (int count = 0; count < enemycount; count++)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int k = 0; k < 3; k++)
			{
				map[input->y + i][input->x + k] = 0;
			}
		}
	}
}

void Enemy::MoveRightEnemy(int map[40][20])
{
	EnemyMember* mrEnemy = eSave;
	for (int i = 0; i < enemycount; i++)
	{
		if (mrEnemy->x < 16)
		{
			MoveDeleteAllEnemy(map);
			mrEnemy->x++;
			ShowEnemy(map);
		}
		else
		{
			break;
		}
		mrEnemy = mrEnemy->efMember;
	}
}

void Enemy::MoveLeftEnemy(int map[40][20])
{
	EnemyMember* mrEnemy = eSave;
	for (int i = 0; i < enemycount; i++)
	{
		if (mrEnemy->x > 1)
		{
			MoveDeleteAllEnemy(map);
			mrEnemy->x--;
			ShowEnemy(map);
		}
		else
		{
			break;
		}
		mrEnemy = mrEnemy->efMember;
	}
}

void Enemy::HitEnemy(int map[40][20])
{
	EnemyMember* mhEnemy = eSave;
	for (int i = 0; i < enemycount; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			for (int j = 0; j < 3; j++)
			{
				mhEnemy->member[k][j] = map[mhEnemy->y + k][mhEnemy->x + j];
			}
		}
		mhEnemy = mhEnemy->efMember;
	}
}

void Enemy::DestroyEnemy(int map[40][20])
{
	bool check = false;
	EnemyMember* deEnemy = eSave;
	EnemyMember* desEnemy;

	for (int count = 0; count < enemycount; count++)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int k = 0; k < 3; k++)
			{
				if (deEnemy->member[i][k] > 1)
				{
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
			MoveDeleteEnemy(deEnemy, map);
			deEnemy->ebMember->efMember = deEnemy->efMember;
			deEnemy->efMember->ebMember = deEnemy->ebMember;
			desEnemy = deEnemy->efMember;

			delete deEnemy;
			deEnemy = desEnemy;
			enemycount--;
		}
		else
		{
			deEnemy = deEnemy->efMember;
		}
	}
}

void Enemy::ReleaseEnemy()
{
	EnemyMember* erSave;
	for (int i = 0; i < enemycount; i++)
	{
		erSave = eSave->efMember;
		delete eSave;

		eSave = erSave;
	}
}

