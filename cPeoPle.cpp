#include "cPeoPle.h"
cPeoPle::cPeoPle()
{
	m_x = WIDHT/2 -10;
	m_y = HEIGHT-2;
	m_State = true;
}
cPeoPle::cPeoPle(int x, int y) :toaDo(x,y)
{
	m_State = true;
}
void cPeoPle::Up()
{
	if (m_y - 1 != 1)
	{
		m_y--;
	}
	
}
void cPeoPle::Down()
{
	if (m_y + 1 != HEIGHT-1)
		m_y++;
}
void cPeoPle::Left()
{
	
	if (m_x - 1 != 0)
	{
		m_x--;
	}
}
void cPeoPle::Right()
{
	if (m_x != WIDHT - 1)
	{
		m_x++;
	}
	
}
bool cPeoPle::isFinish()
{
	if (m_y == 2)
	{
		return true;
	}
	return false;
}

bool cPeoPle::isDead()
{
	return !m_State;
}
void cPeoPle::draw()
{

	TextColor(ColorCode_Yellow);
	gotoXY(m_x, m_y);
	printf("%c", 233);
	gotoXY(m_x, m_y+1);
	printf("V");
	TextColor(7);
}
void cPeoPle::deleteChar()
{
	gotoXY(m_x, m_y);
	cout <<' ';
	gotoXY(m_x, m_y+1);
	cout <<' ';
}
void cPeoPle::reSet()
{
	m_x = WIDHT / 2;
	m_y = HEIGHT - 2;
	m_State = true;
}
bool cPeoPle::isImpact(cTruck *p, int lv)
{
	return false;
}
bool cPeoPle::isImpact(cCar *p, int lv)
{
	return false;
}
bool cPeoPle::isImpact(cBird *p, int lv)
{
	return false;
}
bool cPeoPle::isImpact(cDinausor *p, int lv)
{
	return false;
}
