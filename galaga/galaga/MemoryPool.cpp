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

void MemoryPool::Destroy(bullet* bCheck, int map[40][20])
{
	if (bCheck->check == 1)
	{
		map[bCheck->y][bCheck->x] = 0;

		bCheck->bBefore->bNext = bCheck->bNext;
		bCheck->bNext->bBefore = bCheck->bBefore;

		delete bCheck;

		count--;
	}
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
			if (bMBSave->y > 0)
			{
				if (map[bMBSave->y][bMBSave->x] < 2)
				{
					map[bMBSave->y][bMBSave->x] = 0;
					bMBSave->y--;
					map[bMBSave->y][bMBSave->x] += 1;
				}
				else if (map[bMBSave->y][bMBSave->x] >= 2)
				{
					bMBSave->check = 1;
					map[bMBSave->y][bMBSave->x] = 2;
				}
			}
			else
			{
				bMBSave->check = 1;
				Destroy(bMBSave,map);
			}
			
		}
		else if (bMBSave->num == 0)
		{
			if (bMBSave->y < 39)
			{
				map[bMBSave->y][bMBSave->x] = 0;
				bMBSave->y++;
				map[bMBSave->y][bMBSave->x] += 1;
			}
			else
			{
				bMBSave->check = 1;
				Destroy(bMBSave, map);
			}
		}
		bMBSave = bMBSave->bNext;
	}
}

void MemoryPool::CheckBullet(int map[40][20])
{
	bullet* bcbSave = bfSave;
	for (int i = 0; i < count; i++)
	{
		if (bcbSave->check == 1)
		{
			Destroy(bcbSave, map);
		}
		bcbSave = bcbSave->bNext;

	}
}