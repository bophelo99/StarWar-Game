#include "time.h"
#include <ctime>
using namespace std;
timer::timer()
:Time_start{0.0},
 Time_pause{0.0},
 Time_resume{0.0},
 Time_run{0.0},
 Time_lap{0.0},
 Time_stop{0.0},
 Timemode_{TimeMode::STOP}
{
    //ctor
}

void timer::resertTimer()
{
 Time_start = 0.0;
 Time_pause = 0.0;
 Time_resume = 0.0;
 Time_run = 0.0;
 Time_lap = 0.0;
 Time_stop = 0.0;
 Timemode_ = TimeMode::STOP;
}

void timer::Start()
{
   if(Timemode_ != TimeMode::RUN) Timemode_ = TimeMode::RUN;
   Time_start = GetProcessTime(); Time_run = 0.0f;
   return;
}

void timer::Pause()
{
   if(Timemode_ != TimeMode::PAUSE)Timemode_ = TimeMode::PAUSE;
   Time_pause = GetProcessTime();
   return;
}

void timer::Resume()
{
    if(Timemode_ == TimeMode::PAUSE){
        Timemode_ = TimeMode::RUN;
        Time_resume = GetProcessTime();
        Time_run -=(Time_resume - Time_pause);
        Time_lap +=(Time_resume - Time_pause);
    }
    return;
}

void timer::Stop()
{
     if(Timemode_ != TimeMode::STOP) Timemode_ = TimeMode::STOP;
     Time_stop = GetProcessTime();
    return;
}

double timer::getLapTime()
{
   if(Timemode_ != TimeMode::STOP || Timemode_ == TimeMode::PAUSE)
    Time_lap = GetProcessTime() - Time_lap;
   return Time_lap;
}

double timer::getPauseTime()
{
  return Time_pause;
}

double timer::getStopTime()
{
   Stop();
   return Time_stop-Time_start;
}

double timer::getRunTime()
{
   Time_run +=(Time_stop - Time_start);
   return Time_run;
}

double timer::GetProcessTime()
{
    clock_t time = clock();
    return static_cast<double>(time)/CLOCKS_PER_SEC;
}

