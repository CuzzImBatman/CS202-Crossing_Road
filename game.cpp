#include "game.h"
game::game()
{
	m_level = LV_MIN;
	this->createGame(m_level);
}
void game::lvUp()
{
	peoPle.deleteChar();
	for (int i = 0; i < m_level; i++)
	{
		bird[i].deleteChar();
		dinausor[i].deleteChar();
		truck[i].deleteChar();
		car[i].deleteChar();
	}
	delete[] car;
	delete[] bird;
	delete[] truck;
	delete[] dinausor;
	if (m_level == LV_MAX)
	{
		gotoXY(2, HEIGHT + 2);
		cout << "You win";
		//_getch();
		exit(0);
	}
	m_level++;
	peoPle.reSet();
	this->createGame(m_level);
}
void game::resetGame(int lv)
{
	peoPle.deleteChar();
	for (int i = 0; i < m_level; i++)
	{
		bird[i].deleteChar();
		dinausor[i].deleteChar();
		truck[i].deleteChar();
		car[i].deleteChar();
	}
	for (int i = 0; i < 70; i++)
	{
		gotoXY(i + 1, HEIGHT + 3);
		cout << ' ';
	}
	m_level = lv;
	peoPle.reSet();
	this->createGame(m_level);
}
void game::createGame(int lv)
{
	m_level = lv;
	truck = new cTruck[m_level];
	car = new cCar[m_level];
	bird = new cBird[m_level];
	dinausor = new cDinausor[m_level];
	for (int i = 0; i < m_level; i++)
	{
		int x_vehicle = 8 * i + 5;
		int x_animal = WIDHT - 8 * i - 5;
		truck[i].set(x_vehicle, y_truck);
		car[i].set(x_vehicle, y_car);
		bird[i].set(x_animal, y_bird);
		dinausor[i].set(x_animal, y_dinausor);
	}
}
game::~game()
{
	delete[]car;
	delete[]truck;
	delete[]bird;
	delete[]dinausor;
}
int& game::getLevel()
{
	return m_level;
}
void game::drawGame()
{
	peoPle.draw();
	gotoXY(WIDHT + 10, HEIGHT - 15);
	cout << m_level - LV_MIN + 1;
	for (int i = 0; i < m_level; i++)
	{
		truck[i].draw();
		car[i].draw();
		bird[i].draw();
		dinausor[i].draw();
	}

	if (trafic.getStatus())
	{
		TextColor(ColorCode_Red);
	}
	else
	{
		TextColor(ColorCode_Green);
	}
	gotoXY(0, y_car);
	printf("%c", 223);
	gotoXY(0, y_truck);
	printf("%c", 223);
	TextColor(7);
}
void game::drawBack(const int x, const int y)
{
	TextColor(40);
	for (int i = 30; i <= 60; i++)
	{
		for (int j = y - 3; j <= y + 6; j++)
		{
			if (j == y - 3 || j == y + 6 || i == 30 || i == 60)
			{
				gotoXY(i, j);
				cout << " ";
			}
		}
	}
	TextColor(7);
}
void game::DangNhap()
{
	//mciSendStringA("play nen.mp3", 0, NULL, 0);
	string menu[] = { "Start Game", "Load Game", "Setting","Exit" };
	int pos = 0;
	const int y = 10;
	const int x = 40;
	int flag = 0;
	while (1)
	{
		clrscr();
		int color = rand() % 7 + 9;
		TextColor(40);
		drawBack(x, y);
		for (int i = 0; i < MAX_LIST; i++)
		{
			if (i == pos)
			{
				TextColor(250);
				gotoXY(x, y + i);
				cout << menu[i];
				TextColor(7);
			}
			else
			{
				gotoXY(x, y + i);
				cout << menu[i];
			}
		}
		while (1)
		{
			if (_kbhit())
			{
				char key = _getch();
				if (key == 'W' || key == 'w')
				{
					if (pos > 0)
						pos--;
					else
						pos = MAX_LIST - 1;
					break;
				}
				if (key == 'S' || key == 's')
				{
					if (pos < MAX_LIST - 1)
						pos++;
					else
						pos = 0;
					break;
				}
				if (key == 13)
				{
					switch (pos)
					{
					case 0:
					{
						system("cls");
						startGame();
						flag = 1;
						break;
					}
					case 1:
					{
						system("cls");
						loadGame();
						startGame();
						flag = 1;
						break;
					}
					case 2:
					{
						flag = 1;
						game::gameSetting();
						break;
					}
					case 3:
					{
						exit(0);
						break;
					}
					}
					break;
				}
			}
		}
		if (flag)	break;
	}
}
void game::gameSetting()
{
	system("cls");
	string setting[] = { "Do Kho", "Tat Am Thanh" ,"Bat Am Thanh" ,"Menu" };
	int pos1 = 0;
	const int y = 10;
	const int x = 40;
	int flag = 0;
	while (!flag)
	{
		system("cls");

		drawBack(x, y);
		for (int i = 0; i < MAX_LIST - 1; i++)
		{
			if (i == pos1)
			{
				TextColor(250);
				gotoXY(x, y + i);
				cout << setting[i];
				TextColor(7);
			}
			else
			{
				gotoXY(x, y + i);
				cout << setting[i];
			}
		}
		while (1)
		{
			if (_kbhit())
			{
				char key = _getch();
				if (key == 'W' || key == 'w')
				{
					if (pos1 > 0)
						pos1--;
					else
						pos1 = MAX_LIST - 2;
					break;
				}
				if (key == 'S' || key == 's')
				{
					if (pos1 < MAX_LIST - 1 - 1)
						pos1++;
					else
						pos1 = 0;
					break;
				}
				if (key == 13)
				{
					switch (pos1)
					{
					case 0:
					{
						system("cls");
						drawBack(x, y);
						gotoXY(x, y);
						cout << "Nhap do kho: ";
						cin >> m_level;
						flag = 1;
						break;
					}
					case 1:
					{
						mciSendStringA("stop nen.mp3", 0, NULL, 0);
						sound = false;
						flag = 1;
						break;
					}
					case 2:
					{
						mciSendStringA("play nen.mp3", 0, NULL, 0);
						sound = true;
						flag = 1;
						break;
					}
					case 3:
					{

						flag = 1;
						break;
					}
					}
					break;
				}
			}
		}
		system("cls");
	}
	if (flag == 1)
	{
		system("cls");
		game::DangNhap();
		game::drawGame();
	}
}
bool game::isSound()
{
	return sound;
}
void game::soundOn()
{
	sound = true;
	mciSendStringA("play background.mp3", 0, NULL, 0);
}

void game::soundOff()
{
	sound = false;
	mciSendStringA("stop background.mp3", 0, NULL, 0);
}
void game::startGame()
{
	system("cls");
	TextColor(ColorCode_Pink);
	gotoXY(WIDHT + 3, HEIGHT - 15);
	cout << "level: ";
	gotoXY(WIDHT + 3, HEIGHT - 10);
	cout << "Press W to UP";
	gotoXY(WIDHT + 3, HEIGHT - 13);
	cout << "Press A to LEFT";
	gotoXY(WIDHT + 3, HEIGHT - 12);
	cout << "Press S to DOWN";
	gotoXY(WIDHT + 3, HEIGHT - 11);
	cout << "Press F to RIGHT";
	gotoXY(WIDHT + 3, HEIGHT - 10);
	cout << "Press P to PauseGame";
	gotoXY(WIDHT + 3, HEIGHT - 9);
	cout << "Press L to SaveGame";
	gotoXY(WIDHT + 3, HEIGHT - 8);
	cout << "Press E to Exit";
	gotoXY(WIDHT + 3, HEIGHT - 7);
	cout << "Press T to LoadGame";
	gotoXY(WIDHT + 3, HEIGHT - 6);
	cout << "Press SPACE to Turn";
	gotoXY(WIDHT + 3, HEIGHT - 5);
	cout << "       On/Off Sound";
	TextColor(7);
	TextColor(187);
	for (int i = 1; i <= WIDHT + 25; i++)
	{
		gotoXY(i, 1);
		cout << "*";
		gotoXY(i, HEIGHT);
		cout << "*";
	}
	for (int i = 2; i < HEIGHT; i++)
	{
		gotoXY(0, i);
		cout << "*";
		gotoXY(WIDHT, i);
		cout << "*";
		gotoXY(WIDHT + 25, i);
		cout << "*";
	}
	TextColor(7);
}

bool game::isRunning()
{
	return (!peoPle.isDead());
}
cPeoPle game::getPeople()
{
	return peoPle;
}
cTraffic game::getTraffic()
{
	return trafic;
}
void game::updatePosPeople(char moving)
{
	peoPle.deleteChar();
	if (moving == 'a' || moving == 'A')
	{
		peoPle.Left();
	}
	else if (moving == 'w' || moving == 'W')
	{
		peoPle.Up();
	}
	else if (moving == 'd' || moving == 'D')
	{
		peoPle.Right();
	}
	else if (moving == 's' || moving == 'S')
	{
		peoPle.Down();
	}
}
void game::exitGame(HANDLE t)
{
	system("cls");
	exit(0);
}
void game::pauseGame(HANDLE t)
{
	SuspendThread(t);
}
void game::resumeGame(HANDLE t)
{
	ResumeThread(t);
}

void  game::updatePosAnimal()
{
	for (int i = 0; i < m_level; i++)
	{
		bird[i].deleteChar();
		bird[i].move();
	}
	for (int i = 0; i < m_level; i++)
	{
		dinausor[i].deleteChar();
		dinausor[i].move();
	}
}
void game::updatePosVehicle()
{
	for (int i = 0; i < m_level; i++)
	{

		car[i].deleteChar();
		car[i].move();

	}
	for (int i = 0; i < m_level; i++)
	{
		truck[i].deleteChar();
		truck[i].move();

	}
}
void  game::updateTraffic()
{
	trafic.updateTime();
}
cTruck* game::getTruck()
{
	return truck;
}
cBird* game::getBird()
{
	return bird;
}
cCar* game::getCar()
{
	return car;
}
cDinausor* game::getDinausor()
{
	return dinausor;
}
int game::speedGame()
{
	return 200 - (m_level - LV_MIN) * 30;
}
void game::saveGame()
{
	TextColor(ColorCode_Green);
	ofstream outfile;
	string file;
	gotoXY(WIDHT / 2, HEIGHT + 2);
	cout << "Nhap ten  Can Luu" << endl;
	getline(cin, file);
	file = file + ".txt";
	outfile.open(file);
	TextColor(7);
	outfile << m_level << ' ';
	outfile << peoPle.getX() << ' ' << peoPle.getY() << endl;
	outfile << trafic.getStatus() << ' ' << trafic.getTime() << endl;

	for (int i = 0; i < m_level; i++)
	{
		outfile << car[i].getX() << ' ';
		outfile << car[i].getY() << ' ';
	}
	for (int i = 0; i < m_level; i++)
	{
		outfile << truck[i].getX() << ' ';
		outfile << truck[i].getY() << ' ';
	}
	for (int i = 0; i < m_level; i++)
	{
		outfile << bird[i].getX() << ' ';
		outfile << bird[i].getY() << ' ';
	}
	for (int i = 0; i < m_level; i++)
	{
		outfile << dinausor[i].getX() << ' ';
		outfile << dinausor[i].getY() << ' ';
	}
	outfile.close();
	clrscr();
	this->startGame();
	this->drawGame();
	return;
}
void game::drawDie()
{
	system("cls");
	TextColor(ColorCode_White);
	gotoXY(WIDHT + 3, HEIGHT - 13);
	cout << "Press E to Exit";
	gotoXY(WIDHT + 3, HEIGHT - 12);
	cout << "Press T to LoadGame";
	gotoXY(WIDHT + 3, HEIGHT - 6);
	cout << "Press SPACE to Turn";
	gotoXY(WIDHT + 3, HEIGHT - 5);
	cout << "       On/Off Sound";
	for (int i = 1; i <= WIDHT + 25; i++)
	{
		gotoXY(i, 1);
		cout << "*";
		gotoXY(i, HEIGHT);
		cout << "*";
	}
	for (int i = 2; i < HEIGHT; i++)
	{
		gotoXY(0, i);
		cout << "*";
		gotoXY(WIDHT, i);
		cout << "*";
		gotoXY(WIDHT + 25, i);
		cout << "*";
	}
	TextColor(7);
}
void game::loadGame()
{
	ifstream loadfile;
	string file;
	gotoXY(WIDHT / 2, HEIGHT + 2);
	cout << "Nhap ten  Can tai len" << endl;
	getline(cin, file);
	file = file + ".txt";
	clrscr();
	loadfile.open(file, ios::in);
	if (loadfile.fail())
	{
		gotoXY(WIDHT / 2, HEIGHT / 2);
		TextColor(ColorCode_Green);
		cout << "DU LIEU KHONG TON TAI, BAT DAU TRO CHOI." << endl;
		TextColor(7);
		system("pause");
		clrscr();
		return;
	}
	delete[] car;
	delete[] truck;
	delete[] bird;
	delete[] dinausor;
	loadfile >> m_level;
	car = new cCar[m_level];
	truck = new cTruck[m_level];
	bird = new cBird[m_level];
	dinausor = new cDinausor[m_level];
	int x, y, status, time;
	loadfile >> x;
	loadfile >> y;
	peoPle.set(x, y);
	loadfile >> status;
	loadfile >> time;
	trafic.set(status, time);
	for (int i = 0; i < m_level; i++)
	{
		loadfile >> x;
		loadfile >> y;
		car[i].set(x, y);
	}
	for (int i = 0; i < m_level; i++)
	{
		loadfile >> x;
		loadfile >> y;
		truck[i].set(x, y);
	}
	for (int i = 0; i < m_level; i++)
	{
		loadfile >> x;
		loadfile >> y;
		bird[i].set(x, y);
	}
	for (int i = 0; i < m_level; i++)
	{
		loadfile >> x;
		loadfile >> y;
		dinausor[i].set(x, y);
	}
	loadfile.close();
}