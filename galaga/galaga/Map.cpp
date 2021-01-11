#include "Map.h"

void Map::InitMap()
{
	for (int i = 0; i < 40; i++)
	{
		for (int k = 0; k < 20; k++)
		{
			if (i == 0 || i == 39) // 세로 맵 테두리 생성
			{
				map[i][k] = 1;
			}
			else if (k == 0 || k == 19) // 가로 맵 테두리 생성
			{
				map[i][k] = 1;
			}
			else // 빈 칸 생성
			{
				map[i][k] = 0;
			}
		}
	}
}

void Map::UpdateMap(int playerhp)
{
	for (int i = 0; i < 40; i++)
	{
		for (int k = 0; k < 20; k++)
		{
			if (map[i][k] == 1 || map[i][k] == 2) // 맵 좌표안의 값이 1 또는 2 일 경우
			{
				WriteBuffer(k, i, "■"); 
			}
			else // 그 외 해당하는 값이 들어갈 경우
			{
				WriteBuffer(k, i, "□");
			}
		}
	}

	WriteBuffer(9, 42, "Player HP : ");

	if (playerhp == 1)
	{
		WriteBuffer(21, 42, "1");
	}
	else if (playerhp == 2)
	{
		WriteBuffer(21, 42, "2");
	}
	else if (playerhp == 3)
	{
		WriteBuffer(21, 42, "3");
	}


	WriteBuffer(1, 45, "방향키 :  움직임");
	WriteBuffer(1, 46, "SPACE BAR :  발사");

}

void Map::NextStageUI()
{
	InitMap();

	for (int i = 0; i < 40; i++)
	{
		for (int k = 0; k < 20; k++)
		{
			if (map[i][k] == 1 || map[i][k] == 2) // 맵 좌표안의 값이 1 또는 2 일 경우
			{
				WriteBuffer(k, i, "■");
			}
			else // 그 외 해당하는 값이 들어갈 경우
			{
				WriteBuffer(k, i, "□");
			}
			WriteBuffer(8, 15, "NEXT STAGE");
		}
	}

	for (int i = 1; i <= 6; i++)
	{
		WriteBuffer(17 + i, 15, "□");
	}
	WriteBuffer(24, 15, "■");

}

void Map::StartMenuUI(int &key, int number)
{
	WriteBuffer(12, 5, "GALAGA Ver.0.0.1");
	WriteBuffer(11, 10, "1. Start Game");
	WriteBuffer(11, 12, "2. Exit");

	if (number == 0)
	{
		WriteBuffer(8, 10, "▶");
	}
	else if (number == 1)
	{
		WriteBuffer(8, 12, "▶");
	}
	
}

void Map::GameOverUI()
{

}







void Map::CreateBuffer()
{
	COORD size = { 20, 50 };
	CONSOLE_CURSOR_INFO cci;
	SMALL_RECT rect;
	rect.Bottom = 0;
	rect.Left = 0;
	rect.Right = 19;
	rect.Top = 49;

	hBuffer[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleScreenBufferSize(hBuffer[0], size);
	SetConsoleWindowInfo(hBuffer[0], TRUE, &rect);

	hBuffer[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleScreenBufferSize(hBuffer[1], size);
	SetConsoleWindowInfo(hBuffer[1], TRUE, &rect);

	cci.dwSize = 1;
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(hBuffer[0], &cci);
	SetConsoleCursorInfo(hBuffer[1], &cci);

}

void Map::WriteBuffer(int x, int y, const char str[])
{
	DWORD dw;
	COORD CursorPosition = { x , y };
	SetConsoleCursorPosition(hBuffer[nScreenIndex], CursorPosition);
	WriteFile(hBuffer[nScreenIndex], str, strlen(str) , &dw, NULL);
}

void Map::FlippingBuffer()
{
	SetConsoleActiveScreenBuffer(hBuffer[nScreenIndex]);
	if (nScreenIndex == 0)
	{
		nScreenIndex = 1;
	}
	else if (nScreenIndex == 1)
	{
		nScreenIndex = 0;
	}
}

void Map::ClearBuffer()
{
	COORD Coor = { 0,0 };
	DWORD dw;
	FillConsoleOutputCharacter(hBuffer[nScreenIndex], ' ', 40*20, Coor, &dw);
}

void Map::DeleteBuffer()
{
	CloseHandle(hBuffer[0]);
	CloseHandle(hBuffer[1]);
}
