#pragma once
#include <iostream>
#include <stdlib.h>
#include <Windows.h>

static HANDLE hBuffer[2]; // 이중 버퍼

using namespace std;
class Map 
{
private:
	int nScreenIndex = 0; // 이중버퍼를 관리하기 위한 숫자
public:
	int map[40][20]; // 맵 크기 20X40
public:
	void InitMap(); // 맵 초기화
	void UpdateMap(int playerhp); // 맵 업데이트

	void NextStageUI(); // NEXT STAGE UI
	void StartMenuUI(int& key, int number); // Start Menu UI;
	void GameOverUI(); // GameOver UI

	void CreateBuffer(); // 버퍼 생성
	void WriteBuffer(int x, int y, const char str[]); // 버퍼 쓰기
	void FlippingBuffer(); // 버퍼 교체
	void ClearBuffer(); // 버퍼 초기화
	void DeleteBuffer(); // 버퍼 삭제
};