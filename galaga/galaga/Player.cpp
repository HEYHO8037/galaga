#include "Player.h"

Player::Player()
{

}

void Player::InitPlayer(int map[40][20])
{
	for (int i = 2; i >= 0; i--)
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
	for (int i = 3; i >= 0; i--)
	{
		for (int k = 0; k < 3; k++)
		{
			map[Y + i][center + k] = 0;
		}
	}
}

void Player::CheckPlayerBullet(int map[40][20])
{
	for (int i = 3; i >= 0; i--)
	{
		for (int k = 0; k < 3; k++)
		{
			if (map[Y + i][center + k] > 1)
			{
				break;
			}
		}
	}

	deleteMovePlayer(map);
}


void Player::bulletInit(int map[40][20])
{
	Construct(1, center + 1, Y, map);
}

void Player::bulletMove(int map[40][20])
{
	MoveBullet(map);
}

void Player::bulletCheck(int map[40][20])
{
	CheckBullet(map);
}


