#pragma once

class Bullet
{
protected:
	struct bulletMember
	{
		int select;
		int x, y;
		bool check = false;
	};
	bulletMember* totBul;
	int memCount = 0;

public:
	void Construct(int count);
	void InitBullet(int select, int x, int y, int map[40][20]);
	void Destroy(int map[40][20]);
	void Release();
	void MoveBullet(int map[40][20]);
	void CheckBullet(int map[40][20]);

};