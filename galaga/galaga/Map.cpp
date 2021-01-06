#include "Map.h"

void Map::InitMap()
{
	for (int i = 0; i < 40; i++)
	{
		for (int k = 0; k < 20; k++)
		{
			if (i == 0 || i == 39)
			{
				map[i][k] = 1;
			}
			else if (k == 0 || k == 19)
			{
				map[i][k] = 1;
			}
			else
			{
				map[i][k] = 0;
			}
		}
	}
}

void Map::UpdateMap()
{
	for (int i = 0; i < 40; i++)
	{
		for (int k = 0; k < 20; k++)
		{
			if (map[i][k] == 1)
			{
				WriteBuffer(k, i, "бс");
			}
			else
			{
				WriteBuffer(k, i, "бр");
			}
		}
	}
}




void Map::CreateBuffer()
{
	COORD size = { 20, 40 };
	CONSOLE_CURSOR_INFO cci;
	SMALL_RECT rect;
	rect.Bottom = 0;
	rect.Left = 0;
	rect.Right = 19;
	rect.Top = 39;

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
