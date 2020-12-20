#include "MemoryPool.h"

void* MemoryPool::Construct()
{
	count++;
	bullet* bul = new bullet;
	bSave = bul;
	if (count > 1)
	{
		bul->bNext = bSave;
	}

	return bul;
}

void MemoryPool::Destroy()
{
	bullet* bDSave = bSave;
	for (int i = 0; i < count; i++)
	{
		bDSave = bDSave->bNext;
		if (bDSave->bNext == nullptr)
		{
			break;
		}
	}

	delete bDSave;
	count--;

}

void MemoryPool::Release()
{
	bullet* bRSave;
	for (int i = 0; i < count; i++)
	{
		bRSave = bSave->bNext;
		delete bSave;

		bSave = bRSave;
	}
}