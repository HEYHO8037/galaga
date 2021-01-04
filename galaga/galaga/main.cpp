#include "import.h"

int main(void)
{
	Map* map1 = new Map();
	Player* p1 = new Player();
	Enemy* e1 = new Enemy();

	int stage = 1;

	map1->InitMap();
	p1->InitPlayer(map1->map);
	p1->bulletCreate(100);
	e1->InitEnemy(8);
	e1->bulletCreate(100);

	e1->ShowEnemy(map1->map);
	map1->UpdateMap();

	Sleep(500);

	e1->MoveDeleteAllEnemy(map1->map);
	map1->UpdateMap();

	Sleep(500);

	e1->MoveLeftEnemy(map1->map);
	map1->UpdateMap();

	Sleep(500);

	e1->MoveDeleteAllEnemy(map1->map);
	map1->UpdateMap();

	e1->MoveRightEnemy(map1->map);
	map1->UpdateMap();

	p1->bulletInit(map1->map);
	map1->UpdateMap();

	Sleep(500);

	e1->bulletInit(map1->map);
	map1->UpdateMap();

	while (1)
	{
		Sleep(500);

		p1->bulletMove(map1->map);
		e1->bulletMove(map1->map);

		p1->bulletCheck(e1->enemycount, e1->total, map1->map);
		e1->bulletCheck(p1->center, p1->Y, map1->map);
		e1->HitCheckEnemy(map1->map);

		p1->CheckPlayerBullet(map1->map);
		e1->DestroyEnemy(map1->map);
		p1->bulletDestroy(map1->map);
		e1->bulletDestroy(map1->map);

		map1->UpdateMap();
	}








	delete e1;
	delete p1;
	delete map1;
}