#pragma once
#include "console.h"
#include <vector>
#include <iostream>
#include<unordered_map>

using namespace std;
class toaDo
{
protected:
	//static unordered_map <int,int>*a;

	int m_x;
	int m_y;
public:
	//static unordered_map <int, int> *getmap() { return a; }
	toaDo()
	{
		m_x = 0;
		m_y = 0;
	}
	toaDo(int x, int y)
	{
		m_x = x;
		m_y = y;
	}
	void set(int x, int y)
	{
		m_x = x;
		m_y = y;
	}
	int& getX()
	{
		return m_x;
	}
	int& getY()
	{
		return m_y;
	}
};

