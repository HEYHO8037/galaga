#include "Player.h"

void Player::InitPlayer(int map[40][20])
{
	for (int i = 1; i >= 0; i--)
	{
		for (int k = 0; k < 3; k++)
		{
			map[Y+i][center + k] += playerMember[i][k];
		}
	}
}

void Player::LeftMovePlayer(int map[40][20])
{
	if (center > 1)
	{
		deleteMovePlayer(map);
		center--;
		InitPlayer(map);
	}
}

void Player::RightMovePlayer(int map[40][20])
{
	if (center < 16)
	{
		deleteMovePlayer(map);
		center++;
		InitPlayer(map);
	}
}



void Player::deleteMovePlayer(int map[40][20])
{
	for (int i = 1; i >= 0; i--)
	{
		for (int k = 0; k < 3; k++)
		{
			map[Y + i][center + k] = 0;
		}
	}
}

void Player::CheckPlayerBullet(int map[40][20])
{
	for (int i = 1; i >= 0; i--)
	{
		for (int k = 0; k < 3; k++)
		{
			if (map[Y + i][center + k] > 1)
			{
				check = true;
			}
			else if (map[Y][center] == 2 || map[Y][center + 2] == 2)
			{
				check = true;
			}
		}
	}
	
	if (check)
	{
		dead = true;
		deleteMovePlayer(map);
	}
}


void Player::bulletCreate(int count)
{
	Construct(count);
}


void Player::bulletInit(int map[40][20])
{
	InitBullet(1, center+1, Y-1);
	showBullet(map);
}

void Player::bulletMove(int map[40][20])
{
	MoveBullet(map);
}

void Player::bulletCheck(int num, EnemyMember *save , int map[40][20])
{
	for (int i = 0; i < num; i++)
	{
		if (save->check == false)
		{
			CheckBullet(save->x, save->y, map);
			save += 1;
		}
	}

	save -= (num);
	
}

void Player:: bulletDestroy(int map[40][20])
{
	Destroy(map);
}
void Player::bulletRelease()
{
	Release();
}
