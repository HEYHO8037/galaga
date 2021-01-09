#include "Bullet.h"
using namespace std;

void Bullet::showBullet(int map[40][20])
{
	for (int i = 0; i < memCount; i++)
	{
		if (totBul[i].check == false) // �Ѿ��� Ÿ ��ǥ�� �Ȱɷ� �ִ� ���
		{
			map[totBul[i].y][totBul[i].x] += 1; // �ʿ� ����
		}
	}
}


void Bullet::Construct(int count)
{
	memCount = 0; // �Ѿ� ���� 0���� �ʱ�ȭ
	totBul = new bulletMember[count]; // �迭 �����Ҵ�
}

void Bullet::InitBullet(int ItemSelect, int posX, int posY)
{
	totBul[memCount].select = ItemSelect;
	totBul[memCount].x = posX;
	totBul[memCount].y = posY;
	totBul[memCount].check = false;
	totBul[memCount].destroyed = false;

	memCount++; // �Ѿ� ���� + 1
}

void Bullet::Destroy(int map[40][20])
{
	for (int i = 0; i < memCount; i++)
	{
		if (totBul[i].check == true ) // �Ѿ��� ��ǥ�� �ɷ��� ��
		{
			if (totBul[i].destroyed == false) // �Ѿ��� �ı����� �ʾ��� ��
			{
				map[totBul[i].y][totBul[i].x] = 0; // �ʿ� �ش���ǥ�� 0���� ����
				totBul[i].destroyed = true; // �ı��Ǿ���
			}
			else if (totBul[i].destroyed == true)
			{
				continue; // �ı��� �Ѿ˵��� �ǳ� ��
			}
		}
	}
}

void Bullet::Release()
{
	delete[] totBul; // ���� �Ҵ� ����
}

void Bullet::MoveBullet(int map[40][20])
{
	for (int i = 0; i < memCount; i++)
	{
		if (totBul[i].check == false)
		{
			if (totBul[i].select == 1) // �÷��̾ �߻� �� ���
			{
				map[totBul[i].y][totBul[i].x] = 0; // ���� ��ǥ �Ѿ� ����
				totBul[i].y--; // ��ǥ�� ����
				map[totBul[i].y][totBul[i].x] += 1; // ����� ��ǥ�� �Ѿ� ����
			}
			else if (totBul[i].select == 0) // ���� �߻��� ���
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
				if (totBul[i].x >= posX && totBul[i].x <= posX+2 && // �Ѿ� x��ǥ�� �� �Ǵ� �÷��̾� x��ǥ�� ��ġ�� ���
					totBul[i].y >= posY && totBul[i].y <= posY+1 && // �Ѿ� y��ǥ�� �� �Ǵ� �÷��̾� y��ǥ�� ��ġ�� ���
					map[posY+k][posX+j] > 1) // ���� �ش��ϴ� ��ǥ�� �Ѿ��� �� ���
				{
					totBul[i].check = true; //  �Ѿ� ��ǥ�� �ش� ��ǥ�� �ɸ�
					totBul[i].destroyed = true; // �Ѿ� �ı�
					//�ش� ��ǥ�� ���� 0���� ��ü�� �ʿ䰡 ����(�÷��̾� �� �� ��ǥ ��ġ�� ����))
				}
				else if (totBul[i].y <= 1 || totBul[i].y >= 38) // �Ѿ� ��ǥ�� �� ������ ����� ���
				{
					totBul[i].check = true; // �Ѿ��� �� ������ �ɸ�
					//destroy���� �ʴ� ������ �� ������ ������ ������ 0���� ������ ����� ����� �� ������ ����
				}
			}
		}


	}
}