#pragma once
#include "cAnimal.h"
class cBird : public cAnimal
{
public:
	cBird() : cAnimal()
	{

	}
	cBird(int x, int y) :cAnimal(x, y)
	{

	}
	void draw()
	{
		TextColor(ColorCode_DarkRed);
		gotoXY(m_x, m_y);
		printf("%c", 219);
		gotoXY(m_x - 1, m_y - 1);
		printf("%c", 219);
		gotoXY(m_x + 1, m_y - 1);
		printf("%c", 219);
		TextColor(7);
	}
	void deleteChar()
	{
		gotoXY(m_x, m_y);
		cout << ' ';
		gotoXY(m_x - 1, m_y - 1);
		cout << ' ';
		gotoXY(m_x + 1, m_y - 1);
		cout << ' ';
	}
};

