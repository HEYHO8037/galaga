#pragma once
#include <iostream>
#include <stdlib.h>
#include <Windows.h>

static HANDLE hBuffer[2];

using namespace std;
class Map 
{
private:
	int nScreenIndex = 0;
public:
	int map[40][20];
public:
	void InitMap();
	void UpdateMap();
	void CreateBuffer();
	void WriteBuffer(int x, int y, const char str[]);
	void FlippingBuffer();
	void ClearBuffer();
	void DeleteBuffer();
};