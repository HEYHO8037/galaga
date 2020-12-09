#include "Player.h"

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


