#pragma once
#define MAX_TIME 15
class cTraffic
{
private:
	bool m_status;
	int m_time;
public:
	cTraffic();
	bool getStatus();
	int getTime();
	void set(bool status, int time);
	void changeStatus();
	void updateTime();
};

