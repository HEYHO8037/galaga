#include "Bullet.h"
using namespace std;

void Bullet::showBullet(int map[40][20])
{
	for (int i = 0; i < memCount; i++)
	{
		if (totBul[i].check == false)
		{
			map[totBul[i].y][totBul[i].x] += 1;
		}
	}
}


void Bullet::Construct(int count)
{
	memCount = 0;
	totBul = new bulletMember[count];
}

void Bullet::InitBullet(int ItemSelect, int posX, int posY)
{
	totBul[memCount].select = ItemSelect;
	totBul[memCount].x = posX;
	totBul[memCount].y = posY;
	totBul[memCount].check = false;
	totBul[memCount].check = false;

	memCount++;
}

void Bullet::Destroy(int map[40][20])
{
	for (int i = 0; i < memCount; i++)
	{
		if (totBul[i].check == true )
		{
			map[totBul[i].y][totBul[i].x] = 0;
			totBul[i].destroyed = true;
		}
	}
}

void Bullet::Release()
{
	delete[] totBul;
}

void Bullet::MoveBullet(int map[40][20])
{
	for (int i = 0; i < memCount; i++)
	{
		if (totBul[i].check == false)
		{
			if (totBul[i].select == 1)
			{
				map[totBul[i].y][totBul[i].x] = 0;
				totBul[i].y--;
				map[totBul[i].y][totBul[i].x] += 1;
			}
			else if (totBul[i].select == 0)
			{
				map[totBul[i].y][totBul[i].x] = 0;
				totBul[i].y++;
				map[totBul[i].y][totBul[i].x] += 1;
			}
		}
	}
}

void Bullet::CheckBullet(int posX, int posY, int map[40][20])
{
	for (int i = 0; i < memCount; i++)
	{
		if ((posX + 2 >= totBul[i].x >= posX) &&
			(posY + 1 >= totBul[i].y >= posY))
		{
			totBul[i].check = true;
		}
		else if (totBul[i].y <= 1 || totBul[i].y >= 38)
		{
			totBul[i].check = true;
		}
	}
}