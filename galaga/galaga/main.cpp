#include "import.h"

int main(void)
{
	Map* map1 = new Map();
	Player* p1 = new Player();
	Enemy* e1 = new Enemy();

	map1->InitMap();
	p1->InitPlayer(map1->map);

	p1->ShotPlayerBullet(map1->map);
	map1->UpdateMap();
	Sleep(1000);

	p1->MoveDeleteBullet(map1->map);
	map1->UpdateMap();
	Sleep(1000);

	p1->MovePlayerBullet(map1->map);
	map1->UpdateMap();
	Sleep(1000);

	p1->MoveDeleteBullet(map1->map);
	map1->UpdateMap();
	Sleep(1000);

	p1->ShotPlayerBullet(map1->map);
	map1->UpdateMap();
	Sleep(1000);

	delete e1;
	delete p1;
	delete map1;
}