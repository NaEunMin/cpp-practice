#ifndef SCHEDULEFCFS_H
#define SCHEDULEFCFS_H

#include "Schedule.h"

class ScheduleFCFS : public Schedule {
public:
	ScheduleFCFS(string name, int floor[], int current = 0);
	virtual void run();
};

#endif