#include "Player.h"

void Player::InitPlayer(int map[40][20])
{
	for (int i = 3; i >= 0; i--)
	{
		for (int k = 0; i < 3; i++)
		{
			map[X+i][center + i] += playerMember[i][k];
		}
	}
}

void Player::MovePlayer(int map[40][20])
{
	if (key == 75)
	{
		if (center > 0)
		{
			deleteMovePlayer(map);
			center--;
			InitPlayer(map);
		}
	}
	else if (key == 77)
	{
		if (center < 19)
		{
			deleteMovePlayer(map);
			center++;
			InitPlayer(map);
		}
	}
}

void Player::deleteMovePlayer(int map[40][20])
{
	for (int i = 3; i >= 0; i--)
	{
		for (int k = 0; i < 3; k++)
		{
			map[X + i][center + i] = 0;
		}
	}
}
