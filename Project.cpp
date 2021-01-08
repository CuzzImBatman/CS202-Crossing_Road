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
	CONSOLE_CURSOR_INFO cursor;
	cursor.bVisible = Cursor;
	cursor.dwSize = 20;
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
		if (gaming->getPeople().isImpact(gaming->getBird(), lv)
			|| gaming->getPeople().isImpact(gaming->getDinausor(), lv)
			|| gaming->getPeople().isImpact(gaming->getCar(), lv)
			|| gaming->getPeople().isImpact(gaming->getTruck(), lv))
		{
			//DIE
			bool isSound = gaming->isSound();
			gaming->soundOff();
			if (isSound)mciSendStringA("play die.mp3", 0, NULL, 0);
			//mciSendStringA
			ShowCur(false); //xóa dấu nháy con trỏ.

			gaming->drawDie();
			gotoXY(1, HEIGHT + 3);
			cout << " nhan Y de tiep tuc tro choi";
			char temp = toupper(_getch());
			if (temp == 'Y')
			{
				//system("pause");
				gaming->startGame();
				gaming->soundOn();
				gaming->resetGame(LV_MIN);
			}
			
			else exit(0);//if(temp!='E' )
			
				
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
	gaming->soundOn();
	ShowCur(false); //xóa dấu nháy con trỏ.
	gaming->DangNhap();
	thread t1(SubThread);
	//mciSendStringA


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
				gaming->soundOff();
				gaming->pauseGame(t1.native_handle());
				system("cls");
				gaming->loadGame();
				int lv = gaming->getLevel();
				
					gaming->startGame();
					gaming->drawGame();
					gaming->soundOn();
				

			}
			else if (temp == 'E')
			{
				{
					//gaming->soundOff();
					gaming->pauseGame(t1.native_handle());
					delete gaming;
					gaming = new game;
					gaming->DangNhap();
					gaming->drawGame();


				}
			}
			else if (temp == 32)
			{
				if (gaming->isSound())gaming->soundOff();
				else gaming->soundOn();
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
			{
				//gaming->startGame();
				gaming->startGame();
				//gaming->soundOn();
				//gaming->resetGame(LV_MIN);
			}
			else {
				gaming->exitGame(t1.native_handle());
				return 0;
			}
		}

	}
	return 0;

}

