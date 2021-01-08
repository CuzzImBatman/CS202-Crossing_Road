#pragma once
#define MAX_ANIMAL 3
#include <iostream>
#include "toaDo.h"
#include "console.h"
using namespace std;
class cAnimal :public toaDo
{
public:
	cAnimal();
	cAnimal(int, int);
	virtual void deleteChar()
	{

	}
	virtual void draw() = 0;
	void new_map()
	{
		//delete[]a;
		//unordered_map<int,int>* a= getmap();
	}

	void move();

};

