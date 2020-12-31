#include "cVehicle.h"



cVehicle::cVehicle() :toaDo()
{
	
}
cVehicle::cVehicle(int x, int y) : toaDo(x,y)
{
}
void cVehicle::move()
{
	m_x--;
	if (m_x == 2)
	{
		m_x = WIDHT-2;
	}
}


