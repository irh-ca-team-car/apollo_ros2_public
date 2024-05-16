#include "cyber/cyber.h"
class DemoTimerComponent : public apollo::cyber::TimerComponent
{
public:
    DemoTimerComponent() : TimerComponent("TimerComponent") {}
    bool Init() override
    {
        return true;
    }
    bool Proc() override
    {
        AINFO << "Timer step";
        return true;
    };
    long IntervalMilliseconds() { return 5000; }
};