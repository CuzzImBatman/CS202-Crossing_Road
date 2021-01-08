#include "cPeoPle.h"
cPeoPle::cPeoPle()
{
	m_x = WIDHT / 2 - 10;
	m_y = HEIGHT - 2;
	m_State = true;
}
cPeoPle::cPeoPle(int x, int y) :toaDo(x, y)
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
	if (m_y + 1 != HEIGHT - 1)
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
	printf("%c", 1);
	gotoXY(m_x, m_y + 1);
	//printf("Y"); 
	printf("%c", 206);
	TextColor(7);
}
void cPeoPle::deleteChar()
{
	gotoXY(m_x, m_y);
	cout << ' ';
	gotoXY(m_x, m_y + 1);
	cout << ' ';
}
void cPeoPle::reSet()
{
	m_x = WIDHT / 2;
	m_y = HEIGHT - 2;
	m_State = true;
}
bool cPeoPle::isImpact(cTruck* p, int lv)
{
	for (int i = 0; i < lv; i++)
	{
		if (p[i].getX() == m_x && p[i].getY() == m_y)
		{
			m_State = false;
			return true;
		}
		if (p[i].getX() - 1 == m_x && p[i].getY() == m_y)
		{
			m_State = false;
			return true;
		}
		if (p[i].getX() - 2 == m_x && p[i].getY() == m_y)
		{
			m_State = false;
			return true;
		}
		if (p[i].getX() == m_x && p[i].getY() == m_y + 1)
		{
			m_State = false;
			return true;
		}
		if (p[i].getX() - 1 == m_x && p[i].getY() == m_y + 1)
		{
			m_State = false;
			return true;
		}
		if (p[i].getX() - 2 == m_x && p[i].getY() == m_y + 1)
		{
			m_State = false;
			return true;
		}
	}
	return false;
}
bool cPeoPle::isImpact(cCar* p, int lv)
{
	for (int i = 0; i < lv; i++)
	{
		if (p[i].getX() == m_x && p[i].getY() == m_y)
		{
			m_State = false;
			return true;
		}
		if (p[i].getX() == m_x && p[i].getY() - 1 == m_y)
		{
			m_State = false;
			return true;
		}
		if (p[i].getX() - 1 == m_x && p[i].getY() == m_y)
		{
			m_State = false;
			return true;
		}
		if (p[i].getX() + 1 == m_x && p[i].getY() == m_y)
		{
			m_State = false;
			return true;
		}
		if (p[i].getX() == m_x && p[i].getY() == m_y + 1)
		{
			m_State = false;
			return true;
		}
		if (p[i].getX() == m_x && p[i].getY() - 1 == m_y + 1)
		{
			m_State = false;
			return true;
		}
		if (p[i].getX() - 1 == m_x && p[i].getY() == m_y + 1)
		{
			m_State = false;
			return true;
		}
		if (p[i].getX() + 1 == m_x && p[i].getY() == m_y + 1)
		{
			m_State = false;
			return true;
		}
	}
	return false;
}
bool cPeoPle::isImpact(cBird* p, int lv)
{
	for (int i = 0; i < lv; i++)
	{
		if (p[i].getX() == m_x && p[i].getY() == m_y)
		{
			m_State = false;
			return true;
		}
		if (p[i].getX() - 1 == m_x && p[i].getY() - 1 == m_y)
		{
			m_State = false;
			return true;
		}
		if (p[i].getX() + 1 == m_x && p[i].getY() - 1 == m_y)
		{
			m_State = false;
			return true;
		}
		if (p[i].getX() == m_x && p[i].getY() == m_y + 1)
		{
			m_State = false;
			return true;
		}
		if (p[i].getX() - 1 == m_x && p[i].getY() - 1 == m_y + 1)
		{
			m_State = false;
			return true;
		}
		if (p[i].getX() + 1 == m_x && p[i].getY() - 1 == m_y + 1)
		{
			m_State = false;
			return true;
		}
	}
	return false;
}
bool cPeoPle::isImpact(cDinausor* p, int lv)
{
	for (int i = 0; i < lv; i++)
	{
		if (p[i].getX() == m_x && p[i].getY() == m_y)
		{
			m_State = false;
			return true;
		}
		if (p[i].getX() + 1 == m_x && p[i].getY() - 1 == m_y)
		{
			m_State = false;
			return true;
		}
		if (p[i].getX() + 1 == m_x && p[i].getY() == m_y)
		{
			m_State = false;
			return true;
		}
		if (p[i].getX() - 1 == m_x && p[i].getY() == m_y)
		{
			m_State = false;
			return true;
		}
		if (p[i].getX() == m_x && p[i].getY() == m_y + 1)
		{
			m_State = false;
			return true;
		}
		if (p[i].getX() + 1 == m_x && p[i].getY() - 1 == m_y + 1)
		{
			m_State = false;
			return true;
		}
		if (p[i].getX() + 1 == m_x && p[i].getY() == m_y + 1)
		{
			m_State = false;
			return true;
		}
		if (p[i].getX() - 1 == m_x && p[i].getY() == m_y + 1)
		{
			m_State = false;
			return true;
		}
	}
	return false;
}

