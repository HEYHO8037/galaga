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

	int center = 10;
	int X = 3;
	int key = getch();

public:
	void InitPlayer(int map[40][20]);
	void MovePlayer(int map[40][20]);
	void deleteMovePlayer(int map[40][20]);
};
