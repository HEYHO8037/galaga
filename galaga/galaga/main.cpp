#include "import.h"

int main(void)
{
	system("mode con cols=50 lines=60");

	int key = 0;
	bool start = true;
	Map* map1 = new Map();
	Player* p1 = new Player();
	Enemy* e1 = new Enemy();
	int stage = 1;


	while (stage)
	{

		if (start)
		{
			map1->InitMap();
			map1->CreateBuffer();
			p1->InitPlayer(map1->map);
			p1->bulletCreate(100);
			e1->bulletCreate(100);

			if (stage == 1)
			{
				e1->InitEnemy(8);
			}
			else if (stage == 2)
			{
				e1->InitEnemy(8);
			}
			else if (stage == 3)
			{
				e1->InitEnemy(10);
			}
			e1->ShowAllEnemy(map1->map);
			start = false;
		}
		else if (start == false)
		{
			Sleep(50);

			map1->ClearBuffer();
			map1->UpdateMap();
			map1->FlippingBuffer();

			if (_kbhit())
			{
				key = _getch();
				if (key == 224)
				{
					key = _getch();
					switch (key)
					{
					case 75:
						p1->LeftMovePlayer(map1->map);
						break;
					case 77:
						p1->RightMovePlayer(map1->map);
						break;
					default:
						break;
					}
				}
				else
				{
					if (key == 32)
					{
						p1->bulletInit(map1->map);
					}
				}
			}

  			e1->MoveRandEnemy(map1->map);
			e1->RandBullet(map1->map);

			e1->bulletMove(map1->map);
			p1->bulletMove(map1->map);

			p1->CheckPlayerBullet(map1->map);
			e1->bulletCheck(p1->center, p1->Y, map1->map);
			e1->bulletDestroy(map1->map);

			e1->HitCheckEnemy(map1->map);
			p1->bulletCheck(e1->enemycount, e1->total, map1->map);
			p1->bulletDestroy(map1->map);

			
			

			if (e1->mEnemycount == 0)
			{
				e1->ReleaseAllEnemy();
				e1->bulletRelease();
				p1->bulletRelease();
				map1->DeleteBuffer();
				start = true;
				stage++;
			}
			if ((stage == 3 && e1->mEnemycount == 0) || p1->dead == true)
			{
				e1->ReleaseAllEnemy();
				e1->bulletRelease();
				p1->bulletRelease();
				map1->DeleteBuffer();

				delete e1;
				delete p1;
				delete map1;

				exit(0);
			}
		}
	}
}