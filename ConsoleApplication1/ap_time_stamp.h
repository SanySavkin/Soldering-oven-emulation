#ifndef AP_TIME_STAMP_H
#define AP_TIME_STAMP_H


#include "stdint.h"


class TimeStamp
{
private:
	TimeStamp();
	static uint32_t startTime;
public:
	static void Init();
	static uint32_t GetMillis();
};



#endif //AP_TIME_STAMP_H

