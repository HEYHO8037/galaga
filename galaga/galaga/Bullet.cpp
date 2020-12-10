#include "Bullet.h"

Bullet::Bullet()
{

}

Bullet::Bullet(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Bullet::ShotBullet(int map[40][20])
{
	map[this->y][this->x] += 1;
}

void Bullet::MoveBullet(int check, int map[40][20])
{
	if (check == 1)
	{
		y += 1;
	}
	else if (check == 0)
	{
		y -= 1;
	}
	map[y][x] += 1;
}

void Bullet::DeleteBullet(int map[40][20])
{
	map[y][x] = 0;
}