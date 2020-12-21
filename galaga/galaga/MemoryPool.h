#pragma once

class MemoryPool
{
protected:
	struct bullet
	{
		int x, y;
		int num;
		int check;
		bullet* bBefore = nullptr;
		bullet* bNext = nullptr;
	};
	int count = 0;
	bullet* bfSave = nullptr;

public:
	void Construct(int select, int posX, int posY, int map[40][20]);
	void Destroy(int map[40][20]);
	void Release();
	void MoveBullet(int map[40][20]);
	void CheckBullet(int map[40][20]);

};