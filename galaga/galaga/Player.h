#pragma once
#include "Bullet.h"
#include "Enemy.h"

class Player : Bullet
{
private:
	int playerMember[2][3] =
	{
		{0,1,0},
		{1,1,1}
	};
public:
	int center = 10;
	int Y = 30;
	bool dead = false;
	int hp = 3;

public:
	void InitPlayer(int map[40][20]);
	void LeftMovePlayer(int map[40][20]);
	void RightMovePlayer(int map[40][20]);
	void deleteMovePlayer(int map[40][20]);

public:
	void bulletCreate(int count);
	void CheckPlayerBullet(int map[40][20]);
	void bulletInit(int map[40][20]);
	void bulletMove(int map[40][20]);
	void bulletCheck(int num, EnemyMember* save, int map[40][20]);
	void bulletDestroy(int map[40][20]);
	void bulletRelease();
};
