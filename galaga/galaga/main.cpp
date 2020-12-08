#include "import.h"

int main(void)
{
	Map* map1 = new Map();
	Player* p1 = new Player();
	Enemy* e1 = new Enemy();

	map1->InitMap();
	p1->InitPlayer(map1->map);
	map1->UpdateMap();

	e1->InitEnemy(8, map1->map);
	map1->UpdateMap();

	delete e1;
	delete p1;
	delete map1;
}