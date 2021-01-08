#pragma once
#include "cPeoPle.h"
#include "cTraffic.h"
#include <vector>
#include <string>
#include <conio.h>
#include <fstream>
#include <time.h>
#pragma comment(lib,"winmm.lib")
#define LV_MAX 8
#define LV_MIN 3
const int y_bird = 16;
const int y_truck = 12;
const int y_car = 8;
const int y_dinausor = 4;
class game
{
private:
	cPeoPle peoPle;
	cTruck* truck;
	cCar* car;
	cBird* bird;
	cDinausor* dinausor;
	int m_level;
	cTraffic trafic;
	bool sound = true;
public:
	game();
	~game();
	void drawGame();
	void createGame(int level);
	void updatePosPeople(char);
	void lvUp();
	void gameSetting();
	void drawDie();
	int speedGame();
	cTruck* getTruck();
	cBird* getBird();
	cDinausor* getDinausor();
	cCar* getCar();
	cPeoPle getPeople();
	cTraffic getTraffic();
	int& getLevel();
	void Delete();
	void DangNhap();
	bool isRunning();
	void resetGame(int lv);
	void exitGame(HANDLE);
	void startGame();
	void loadGame();
	void saveGame();
	void drawBack(const int x, const int y);
	void pauseGame(HANDLE);
	void resumeGame(HANDLE);
	void updatePosVehicle();
	void updatePosAnimal();
	void updateTraffic();
	bool isSound();
	void soundOn();
	void soundOff();

};