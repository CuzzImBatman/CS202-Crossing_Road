#pragma once
#include "cAnimal.h"

class cDinausor : public cAnimal
{
public:
	cDinausor() : cAnimal()
	{

	}
	cDinausor(int x, int y) : cAnimal(x, y)
	{

	}
	void draw()
	{
		TextColor(ColorCode_DarkBlue);
		gotoXY(m_x + 1, m_y - 1);
		printf("%c", 220);
		gotoXY(m_x + 1, m_y);
		printf("%c", 223);
		gotoXY(m_x, m_y);
		printf("%c", 219);
		gotoXY(m_x - 1, m_y);
		printf("%c", 220);
		TextColor(7);
	}
	void deleteChar()
	{
		gotoXY(m_x + 1, m_y - 1);
		cout << ' ';
		gotoXY(m_x + 1, m_y);
		cout << ' ';
		gotoXY(m_x, m_y);
		cout << ' ';
		gotoXY(m_x - 1, m_y);
		cout << ' ';
	}
};

