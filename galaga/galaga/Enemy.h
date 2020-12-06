#pragma once
#include "import.h"

class Enemy
{
private:
	struct EnemyMember
	{
		int member[3][3] =
		{
			{1,1,1},
			{0,1,0},
			{0,0,0}
		};
		int hp = 3;
	};
	int level = 1;

public:
	void InitEnemy();
	void MoveEnemy();
	void MoveDeleteEnemy();
	void EnemyShot();
	void BulletCheck();

};