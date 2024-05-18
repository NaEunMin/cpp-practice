#ifndef SCHEDULESCAN_H
#define SCHEDULESCAN_H
#include "Schedule.h"
class ScheduleSCAN : public Schedule {
public:
	ScheduleSCAN(string name, int floor[], int current = 0);
	virtual void run();
};
#endif