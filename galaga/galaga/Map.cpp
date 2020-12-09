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
	system("cls");
	for (int i = 0; i < 40; i++)
	{
		for (int k = 0; k < 20; k++)
		{
			if (map[i][k] == 1)
			{
				cout << "бс";
			}
			else
			{
				cout << "бр";
			}
		}
		cout << endl;
	}
}
