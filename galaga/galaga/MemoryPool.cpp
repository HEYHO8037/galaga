#include "MemoryPool.h"

void MemoryPool::Construct(int select, int posX, int posY, int map[40][20])
{
	count++;
	bullet* bul = new bullet;
	bul->x = posX;
	bul->y = posY;
	bul->check = 0;
	bul->num = select;

	if (count == 1)
	{
		bul->bNext = nullptr;
		bul->bBefore = nullptr;
	}
	else
	{
		bul->bNext = bfSave;
		bul->bNext->bBefore = bfSave;
	}

	map[bul->y][bul->x] += 1;
	bfSave = bul;

}

void MemoryPool::Destroy(int map[40][20])
{
	bullet* bDSave = bfSave;
	for (int i = 0; i < count; i++)
	{
		bDSave = bDSave->bNext;
		if (bDSave->check == 1)
		{
			break;
		}
	}
	map[bDSave->y][bDSave->x] = 0;

	bDSave->bBefore->bNext = bDSave->bNext;
	bDSave->bNext->bBefore = bDSave->bBefore;

	delete bDSave;

	count--;
}

void MemoryPool::Release()
{
	bullet* bRSave;
	for (int i = 0; i < count; i++)
	{
		bRSave = bfSave->bNext;
		delete bfSave;

		bfSave = bRSave;
	}
}

void MemoryPool::MoveBullet(int map[40][20])
{
	bullet* bMBSave = bfSave;
	for (int i = 0; i < count; i++)
	{
		if (bMBSave->num == 1)
		{
			if (map[bMBSave->y][bMBSave->x] > 1)
			{
				bMBSave->check = 1;
				bMBSave->y++;
				map[bMBSave->y][bMBSave->x] = 1;
			}

			bMBSave->y--;
			map[bMBSave->y + 1][bMBSave->x] = 0;
			map[bMBSave->y][bMBSave->x] += 1;
			
		}
		else if (bMBSave->num == 0)
		{
			if (map[bMBSave->y][bMBSave->x] > 1)
			{
				bMBSave->check = 1;
				bMBSave->y--;
				map[bMBSave->y][bMBSave->x] += 1;
			}

			bMBSave->y++;
			map[bMBSave->y - 1][bMBSave->x] = 0;
			map[bMBSave->y][bMBSave->x] += 1;
		}
		bMBSave = bMBSave->bNext;
	}
}

void MemoryPool::CheckBullet(int map[40][20])
{

}