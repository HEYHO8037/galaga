#include "import.h"

int main(void)
{
	Map* map1 = new Map();
	Player* p1 = new Player();
	Enemy* e1 = new Enemy();

	int stage = 1;

	map1->InitMap();
	p1->InitPlayer(map1->map);


	delete e1;
	delete p1;
	delete map1;
}