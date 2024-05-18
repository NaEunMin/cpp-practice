#ifndef SCHEDULESMDF_H
#define SCHEDULESMDF_H
#include "Schedule.h"
class ScheduleSMDF : public Schedule {
public:
	ScheduleSMDF(string name, int floor[], int current = 0);
	virtual void run();
};
#endif