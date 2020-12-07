#include "import.h"

int main(void)
{
	Enemy* e1 = new Enemy();
	Map* map1 = new Map();
	Player* p1 = new Player();

	map1->InitMap();
	p1->InitPlayer(map1->map);
	map1->UpdateMap();

	e1->InitEnemy(3, map1->map);
	map1->UpdateMap();



	//e1->InitEnemy(map1->map);
	//map1->UpdateMap();
	//e1->InitEnemy(map1->map);
	//map1->UpdateMap();

	e1->MoveDeleteEnemy(map1->map);
	map1->UpdateMap();
}