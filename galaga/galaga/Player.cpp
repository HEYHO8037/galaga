#include "Player.h"

void Player::InitPlayer(int map[40][20])
{
	for (int i = 3; i >= 0; i--)
	{
		for (int k = 0; k < 3; k++)
		{
			map[Y+i][center + k] += playerMember[i][k];
		}
	}
}

void Player::LeftMovePlayer(int map[40][20])
{
	if (center > 0)
	{
		deleteMovePlayer(map);
		center--;
		InitPlayer(map);
	}
}

void Player::RightMovePlayer(int map[40][20])
{
	if (center < 19)
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
			map[Y + i][center + i] = 0;
		}
	}
}


//void Player::ShotBullet(int map[40][20])
//{
//	bullet *blt = new bullet;
//	blt->x = Y;
//	blt->x = center + 1;
//
//	map[blt->y][blt->x] = 1;
//	
//}
//
//void Player::MoveBullet(int map[40][20])
//{
//	map
//}

