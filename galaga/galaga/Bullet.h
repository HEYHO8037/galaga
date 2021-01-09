#pragma once
#include <iostream>
#include <stdlib.h>

class Bullet
{
protected:
	struct bulletMember
	{
		int select; // 0 : 적 발사, 1 : 플레이어 발사
		int x; // 최초 x 좌표
		int y; // 최초 y 좌표
		bool check = false; // 적 혹은 플레이어 좌표에 걸렸는지 확인
		bool destroyed = false; // 총알이 파괴되었는지 확인
	};
	bulletMember* totBul; // 동적할당 할 배열
	int memCount = 0; // 총알 갯수

public:
	void showBullet(int map[40][20]);  // 총알을 맵에 업데이트
	void Construct(int count); // 총알 배열 동적 할당
	void InitBullet(int select, int posX, int posY); // 총알 생성
	void Destroy(int map[40][20]); // 총알 파괴
	void Release(); // 동적할당 해제
	void MoveBullet(int map[40][20]); // 총알 움직임
	void CheckBullet(int posX, int posY, int map[40][20]); // 총알 충돌 체크

};