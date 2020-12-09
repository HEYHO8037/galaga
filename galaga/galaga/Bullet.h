#pragma once

class Bullet
{
private:
	struct bullet
	{
		int x, y;
	};
	bullet bul;

public:
	void ShotBullet(int x, int y, int map[40][20]);
	void MoveBullet(int map[40][20]);
	void DeleteBullet(int mpap[40][20]);
	void CheckBullet(int x, int y, int map[40][20]);
};