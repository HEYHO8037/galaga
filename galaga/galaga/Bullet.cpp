#include "Bullet.h"
using namespace std;

void Bullet::showBullet(int map[40][20])
{
	for (int i = 0; i < memCount; i++)
	{
		if (totBul[i].check == false) // 총알이 타 좌표에 안걸려 있는 경우
		{
			map[totBul[i].y][totBul[i].x] += 1; // 맵에 적용
		}
	}
}


void Bullet::Construct(int count)
{
	memCount = 0; // 총알 갯수 0으로 초기화
	totBul = new bulletMember[count]; // 배열 동적할당
}

void Bullet::InitBullet(int ItemSelect, int posX, int posY)
{
	totBul[memCount].select = ItemSelect;
	totBul[memCount].x = posX;
	totBul[memCount].y = posY;
	totBul[memCount].check = false;
	totBul[memCount].destroyed = false;

	memCount++; // 총알 갯수 + 1
}

void Bullet::Destroy(int map[40][20])
{
	for (int i = 0; i < memCount; i++)
	{
		if (totBul[i].check == true ) // 총알이 좌표에 걸렸을 때
		{
			if (totBul[i].destroyed == false) // 총알이 파괴되지 않았을 때
			{
				map[totBul[i].y][totBul[i].x] = 0; // 맵에 해당좌표를 0으로 적용
				totBul[i].destroyed = true; // 파괴되었음
			}
			else if (totBul[i].destroyed == true)
			{
				continue; // 파괴된 총알들은 건너 뜀
			}
		}
	}
}

void Bullet::Release()
{
	delete[] totBul; // 동적 할당 해제
}

void Bullet::MoveBullet(int map[40][20])
{
	for (int i = 0; i < memCount; i++)
	{
		if (totBul[i].check == false)
		{
			if (totBul[i].select == 1) // 플레이어가 발사 한 경우
			{
				map[totBul[i].y][totBul[i].x] = 0; // 현재 좌표 총알 제거
				totBul[i].y--; // 좌표값 변경
				map[totBul[i].y][totBul[i].x] += 1; // 변경된 좌표로 총알 생성
			}
			else if (totBul[i].select == 0) // 적이 발사한 경우
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
				if (totBul[i].x >= posX && totBul[i].x <= posX+2 && // 총알 x좌표가 적 또는 플레이어 x좌표에 겹치는 경우
					totBul[i].y >= posY && totBul[i].y <= posY+1 && // 총알 y좌표가 적 또는 플레이어 y좌표에 겹치는 경우
					map[posY+k][posX+j] > 1) // 맵의 해당하는 좌표에 총알이 들어간 경우
				{
					totBul[i].check = true; //  총알 좌표가 해당 좌표에 걸림
					totBul[i].destroyed = true; // 총알 파괴
					//해당 좌표에 따로 0으로 교체할 필요가 없음(플레이어 및 적 좌표 겹치기 때문))
				}
				else if (totBul[i].y <= 1 || totBul[i].y >= 38) // 총알 좌표가 맵 밖으로 벗어나는 경우
				{
					totBul[i].check = true; // 총알이 맵 밖으로 걸림
					//destroy하지 않는 이유는 맵 밖으로 나가기 때문에 0으로 지정을 해줘야 연산시 값 변경이 없음
				}
			}
		}


	}
}