#pragma once
#include <iostream>
#include <stdlib.h>
#include <Windows.h>

static HANDLE hBuffer[2]; // ���� ����

using namespace std;
class Map 
{
private:
	int nScreenIndex = 0; // ���߹��۸� �����ϱ� ���� ����
public:
	int map[40][20]; // �� ũ�� 20X40
public:
	void InitMap(); // �� �ʱ�ȭ
	void UpdateMap(); // �� ������Ʈ
	void CreateBuffer(); // ���� ����
	void WriteBuffer(int x, int y, const char str[]); // ���� ����
	void FlippingBuffer(); // ���� ��ü
	void ClearBuffer(); // ���� �ʱ�ȭ
	void DeleteBuffer(); // ���� ����
};