#pragma once
#include "cVehicle.h"
class cTruck : public cVehicle
{
public:
	cTruck() :cVehicle()
	{

	}
	cTruck(int x, int y) : cVehicle(x, y)
	{

	}
	void draw()
	{

		TextColor(ColorCode_Green);
		gotoXY(m_x, m_y);
		printf("%c", 219);
		gotoXY(m_x - 1, m_y);
		printf("%c", 219);
		gotoXY(m_x - 2, m_y);
		printf("%c", 220);
		TextColor(7);
	}
	void deleteChar()
	{

		gotoXY(m_x, m_y);
		cout << ' ';
		gotoXY(m_x - 1, m_y);
		cout << ' ';
		gotoXY(m_x - 2, m_y);
		cout << ' ';
	}
};

