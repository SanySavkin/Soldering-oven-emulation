#include "ap_time_stamp.h"
#include "Windows.h"
#include <chrono>


using namespace std::chrono;


uint32_t TimeStamp::startTime = 0;


static uint32_t timeSinceEpochMillisec() 
{
	return (uint32_t)(duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count());
}

void TimeStamp::Init()
{
	if(startTime == 0) startTime = timeSinceEpochMillisec();
}

uint32_t TimeStamp::GetMillis()
{
	return timeSinceEpochMillisec() - startTime;
}