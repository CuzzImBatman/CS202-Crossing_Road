#pragma once

#include "cBird.h"
#include "cCar.h"
#include "cTruck.h"
#include "cDinausor.h"
class cPeoPle : public toaDo
{
private:
	bool m_State;
public:
	cPeoPle();
	cPeoPle(int, int);
	void reSet();
	void Up();
	void Left();
	void Right();
	void Down();
	bool isFinish();
	bool isDead();
	void draw();
	void deleteChar();
	bool isImpact(cTruck *, int lv);
	bool isImpact(cCar *, int lv);
	bool isImpact(cBird *, int lv);
	bool isImpact(cDinausor *, int lv);
};
