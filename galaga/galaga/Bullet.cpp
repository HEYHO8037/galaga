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
	totBul = new bulletMember[count];
}

void Bullet::InitBullet(int ItemSelect, int posX, int posY)
{
	totBul[memCount].select = ItemSelect;
	totBul[memCount].x = posX;
	totBul[memCount].y = posY;
	totBul[memCount].check = false;

	memCount++;
}

void Bullet::Destroy(int map[40][20])
{
	for (int i = 0; i < memCount; i++)
	{
		if (totBul[i].check == true)
		{
			map[totBul[i].y][totBul[i].x] = 0;
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
		for (int k = 0; k < 2; k++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (totBul[i].x == posX + j && totBul[i].y == posY + k)
				{
					totBul[i].check = true;
				}
				if (totBul[i].x < 0 || totBul[i].x >= 18)
				{
					totBul[i].check = true;
				}
				if (totBul[i].y < 0 || totBul[i].y >= 38)
				{
					totBul[i].check = true;
				}
			}
		}


	}
}