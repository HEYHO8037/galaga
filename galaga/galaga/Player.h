#pragma once
#include "MemoryPool.h"

class Player : MemoryPool
{
protected:
	int playerMember[3][3] =
	{
		{0,0,0},
		{0,1,0},
		{1,1,1}
	};
	int center = 10;
	int Y = 30;

public:
	Player();
	void InitPlayer(int map[40][20]);
	void LeftMovePlayer(int map[40][20]);
	void RightMovePlayer(int map[40][20]);
	void deleteMovePlayer(int map[40][20]);

	void ChcekPlayerBullet(int map[40][20]);
	void bulletInit(int map[40][20]);
	void bulletMove(int map[40][20]);
	void bulletCheck(int map[40][20]);
};
