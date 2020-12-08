#include "import.h"

int main(void)
{
	Enemy* e1 = new Enemy();
	Map* map1 = new Map();
	Player* p1 = new Player();

	map1->InitMap();
	p1->InitPlayer(map1->map);
	map1->UpdateMap();

	e1->InitEnemy(4, map1->map);
	map1->UpdateMap();

	Sleep(1000);
	e1->MoveDeleteEnemy(map1->map);
	map1->UpdateMap();
	
	e1->MoveRightEnemy(map1->map);
	map1->UpdateMap();

	while (1)
	{
		Sleep(1000);
		e1->MoveDeleteEnemy(map1->map);
		map1->UpdateMap();

		e1->MoveRightEnemy(map1->map);
		map1->UpdateMap();
	}


}