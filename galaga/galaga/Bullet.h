#pragma once

class Bullet
{
private:
	int x;
	int y;

public:
	Bullet();
	Bullet(int x, int y);
	void ShotBullet(int map[40][20]);
	void MoveBullet(int check, int map[40][20]);
	void DeleteBullet(int mpap[40][20]);
};