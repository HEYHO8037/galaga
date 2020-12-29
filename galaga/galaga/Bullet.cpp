#include "Bullet.h"

void Bullet::Construct(int count)
{
	total = new bulletMember[count];
}

void Bullet::InitBullet(int ItemSelect, int posX, int posY, int map[40][20])
{
	bulletMember* member = new bulletMember;
	member->x = posX;
	member->y = posY;
	member->select = ItemSelect;

	total[memCount].x = member->x;
	total[memCount].y = member->y;
	total[memCount].select = member->select;
	total[memCount].check = member->check;

	delete member;
	memCount++;
}

void Bullet::Destroy(int map[40][20])
{
	for (int i = 0; i < memCount; i++)
	{
		if (total[i].check == true)
		{
			map[total[i].y][total[i].x] = 0;
			delete[i] total;
		}
	}
}

void Bullet::Release()
{
	delete[] total;
}

void Bullet::MoveBullet(int map[40][20])
{

}

void Bullet::CheckBullet(int map[40][20])
{

}