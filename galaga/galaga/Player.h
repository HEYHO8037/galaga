#pragma once
#include "import.h"

class Player 
{
private:
	int playerMember[3][3] =
	{
		{0,0,0},
		{0,1,0},
		{1,1,1}
	};

public:
	void InitPlayer();
	void MovePlayer();
	void deleteMovePlayer();
	void PlayerShot();
	void BulletCheck();
};
