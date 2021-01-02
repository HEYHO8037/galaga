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

	e1->MoveRightEnemy(map1->map);
	map1->UpdateMap();

	Sleep(500);

	p1->bulletInit(map1->map);
	map1->UpdateMap();

	Sleep(500);

	e1->bulletInit(map1->map);
	map1->UpdateMap();

	Sleep(500);

	e1->bulletMove(map1->map);
	p1->bulletMove(map1->map);
	map1->UpdateMap();


	//while (1)
	//{
	//	e1->checkListEnemy();
	//	p1->bulletMove(map1->map);

	//	e1->HitEnemy(map1->map);
	//	e1->DestroyEnemy(map1->map);
	//	p1->bulletCheck(map1->map);

	//	map1->UpdateMap();

	//}

	//map1->UpdateMap();








	delete e1;
	delete p1;
	delete map1;
}