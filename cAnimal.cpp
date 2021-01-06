#include "cAnimal.h"



cAnimal::cAnimal() :toaDo()
{

}
cAnimal::cAnimal(int x, int y) :toaDo(x, y)
{

}
void cAnimal::move()
{	
	m_x++;
	if (m_x == WIDHT-2)
	{
		m_x = 3;
	}
}
//void cAnimal::deleteChar()
//{
//	
//	cout << ' ';
//}
