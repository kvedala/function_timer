#ifndef __FUNCTION_TIMER_H
#define __FUNCTION_TIMER_H

#ifdef __cplusplus
#include <chrono>
#include <ctime>

using namespace std::chrono;

class function_timer
{
public:
    function_timer(void (*function)(...));
    function_timer(char *fn_name, void (*function)(...));
    double run();

private:
    char *_fn_name = 0;
    high_resolution_clock::time_point _start_time;
    high_resolution_clock::time_point _end_time;
    duration<double> _duration;
};

extern "C"
{
#endif // __cplusplus

    // double function_timer(void (*function)(...));

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __FUNCTION_TIMER_H