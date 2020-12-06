#include "import.h"

int main(void)
{
	Enemy* e1 = new Enemy();
	Map* map1 = new Map();
	Player* p1 = new Player();

	map1->InitMap();
	p1->InitPlayer(map1->map);
	map1->UpdateMap();
	while (1)
	{
		if (_getch() == 75)
		{
			p1->LeftMovePlayer(map1->map);
			map1->UpdateMap();
		}
		//if (_getch() == 77)
		//{
		//	p1->RightMovePlayer(map1->map);
		//	map1->UpdateMap();
		//}
	}
}