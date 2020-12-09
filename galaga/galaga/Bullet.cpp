#include "Bullet.h"

void Bullet::ShotBullet(int x, int y, int map[40][20])
{
	bul.x = x;
	bul.y = y;
	map[bul.y][bul.x] += 1;
}

void Bullet::MoveBullet(int map[40][20])
{
	bul.y += 1;
	map[bul.y][bul.x] = 1;
}

void Bullet::DeleteBullet(int map[40][20])
{
	map[bul.y][bul.x] = 0;
}

void Bullet::CheckBullet(int x, int y, int map[40][20])
{

}