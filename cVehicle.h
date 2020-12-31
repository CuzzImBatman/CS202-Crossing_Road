#pragma once
#include "console.h"
#include "toaDo.h"
#define MAX_VEHICLE 3
class cVehicle : public toaDo
{
public:
	cVehicle();
	cVehicle(int, int);
	void move();
	virtual void draw()
	{

	}
	virtual void deleteChar()
	{

	}
};

