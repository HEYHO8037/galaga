#pragma once
#include <iostream>
#include <stdlib.h>

class Bullet
{
protected:
	struct bulletMember
	{
		int select;
		int x;
		int y;
		bool check = false;
		bool destroyed = false;
	};
	bulletMember* totBul;
	int memCount = 0;

public:
	void showBullet(int map[40][20]);
	void Construct(int count);
	void InitBullet(int select, int posX, int posY);
	void Destroy(int map[40][20]);
	void Release();
	void MoveBullet(int map[40][20]);
	void CheckBullet(int posX, int posY, int map[40][20]);

};