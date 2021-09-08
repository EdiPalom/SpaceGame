#ifndef TIMER_H
#define TIMER_H

class Timer
{
public:
    Timer(double);
    ~Timer();

    bool get_signal(double);

private:
    double d_time;
    double s_time;
};

#endif
