#pragma once
#include "import.h"

class MemoryPool
{
private:
	struct bullet
	{
		int x, y;
		int num;
		bullet* bNext;
	};
	int count = 0;
	bullet* bSave = nullptr;

public:
	void* Construct();
	void Destroy();
	void Release();
	void MoveBullet(int map[40][20]);
	void CheckBullet(int map[40][20]);
};