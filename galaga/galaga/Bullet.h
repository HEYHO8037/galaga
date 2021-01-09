#pragma once
#include <iostream>
#include <stdlib.h>

class Bullet
{
protected:
	struct bulletMember
	{
		int select; // 0 : �� �߻�, 1 : �÷��̾� �߻�
		int x; // ���� x ��ǥ
		int y; // ���� y ��ǥ
		bool check = false; // �� Ȥ�� �÷��̾� ��ǥ�� �ɷȴ��� Ȯ��
		bool destroyed = false; // �Ѿ��� �ı��Ǿ����� Ȯ��
	};
	bulletMember* totBul; // �����Ҵ� �� �迭
	int memCount = 0; // �Ѿ� ����

public:
	void showBullet(int map[40][20]);  // �Ѿ��� �ʿ� ������Ʈ
	void Construct(int count); // �Ѿ� �迭 ���� �Ҵ�
	void InitBullet(int select, int posX, int posY); // �Ѿ� ����
	void Destroy(int map[40][20]); // �Ѿ� �ı�
	void Release(); // �����Ҵ� ����
	void MoveBullet(int map[40][20]); // �Ѿ� ������
	void CheckBullet(int posX, int posY, int map[40][20]); // �Ѿ� �浹 üũ

};