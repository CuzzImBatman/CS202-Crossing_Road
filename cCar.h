#pragma once
#include "cVehicle.h"
class cCar : public cVehicle
{
public:
	cCar() :cVehicle()
	{

	}
	cCar(int x, int y) : cVehicle(x, y)
	{

	}
	void draw()
	{
		TextColor(ColorCode_Yellow);
		gotoXY(m_x, m_y);
		printf("%c", 219);
		gotoXY(m_x, m_y - 1);
		printf("%c", 254);
		gotoXY(m_x - 1, m_y);
		printf("%c", 219);
		gotoXY(m_x + 1, m_y);
		printf("%c", 219);
		TextColor(7);
	}
	void deleteChar()
	{
		gotoXY(m_x, m_y);
		cout << ' ';
		gotoXY(m_x, m_y - 1);
		cout << ' ';
		gotoXY(m_x - 1, m_y);
		cout << ' ';
		gotoXY(m_x + 1, m_y);
		cout << ' ';
	}
};

