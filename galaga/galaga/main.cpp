#include "import.h"

int main(void)
{
	Map* map1 = new Map();
	Player* p1 = new Player();
	Enemy* e1 = new Enemy();

	int stage = 1;

	map1->InitMap();
	p1->InitPlayer(map1->map);

	p1->bulletInit(map1->map);
	map1->UpdateMap();

	e1->InitEnemy(9, map1->map);
	map1->UpdateMap();

	e1->MoveDeleteEnemy(map1->map);
	map1->UpdateMap();

	//while (1)
	//{
	//	p1->bulletMove(map1->map);
	//	map1->UpdateMap();
	//	Sleep(500);
	//}





	delete e1;
	delete p1;
	delete map1;
}