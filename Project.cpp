#include "game.h"
#include <conio.h>
#include <thread>
game* gaming;
char INPUT_KEY;
void FixConsoleWindow()
{
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}
void ShowCur(bool Cursor)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, Cursor };
	SetConsoleCursorInfo(handle, &cursor);
}

void SubThread()
{
	while (gaming->isRunning())
	{
		//delete[]
		if (!gaming->getPeople().isDead())
		{
			gaming->updatePosPeople(INPUT_KEY);////UPDATE POSITION theo thông tin từ main
		}
		INPUT_KEY = ' ';// LOCK
		//UPDATE POSITION
		if (!gaming->getTraffic().getStatus())
		{
			gaming->updatePosVehicle();
		}
		gaming->updatePosAnimal();
		gaming->updateTraffic();
		gaming->drawGame(); //ve
		int lv = gaming->getLevel();
		if (gaming->getPeople().isImpact(gaming->getBird(), lv) || gaming->getPeople().isImpact(gaming->getDinausor(), lv)
			|| gaming->getPeople().isImpact(gaming->getCar(), lv) || gaming->getPeople().isImpact(gaming->getTruck(), lv))
		{
			//DIE
			//mciSendStringA


			gaming->drawDie();
			gotoXY(1, HEIGHT + 3);
			cout << " nhan Y de tiep tuc tro choi";
			char temp = toupper(_getch());
			if (temp == 'Y')
			{
				system("pause");

				gaming->startGame();
				mciSendStringA("play nen.mp3", 0, NULL, 0);
				gaming->resetGame(LV_MIN);
			}

			else
				exit(0);
		}
		if (gaming->getPeople().isFinish())
		{
			// VỀ ĐÍCH
			// LV++

			gaming->lvUp();
		}
		Sleep(gaming->speedGame());

	}
}
int main()
{
	gaming = new game;
	char temp;
	FixConsoleWindow();
	gaming->DangNhap();
	//mciSendStringA
	thread t1(SubThread);
	while (1)
	{
		ShowCur(false); //xóa dấu nháy con trỏ.
		temp = toupper(_getch());
		if (!gaming->getPeople().isDead())
		{
			if (temp == 27)
			{
				gaming->exitGame(t1.native_handle());
			}
			else if (temp == 'P')
			{
				gaming->pauseGame(t1.native_handle());

			}
			else if (temp == 'L')
			{
				gaming->pauseGame(t1.native_handle());
				gaming->saveGame();
			}
			else if (temp == 'T')
			{
				//mciSendStringA dừng nhạc
				gaming->pauseGame(t1.native_handle());
				system("cls");
				gaming->loadGame();
				gaming->startGame();
				gaming->drawGame();
				//mciSendStringA lên nhạc


			}
			else
			{
				gaming->resumeGame((HANDLE)t1.native_handle());
				INPUT_KEY = temp; //UPDATE KEY
			}
		}
		else
		{
			if (temp == 'Y')
				gaming->startGame();
			else {
				gaming->exitGame(t1.native_handle());
				return 0;
			}
		}
	}
	return 0;
	vector<int> v;

	for (int i = 1; i <= 5; i++)
		v.push_back(i);
	v.erase(v.begin(), v.begin() + 3);
}

