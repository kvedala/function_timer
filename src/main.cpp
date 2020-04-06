#include <cstdio>
#include "function_timer.h"

high_resolution_clock::time_point function_timer::start_timer()
{
    this->_start_time = high_resolution_clock::now();
    return this->_start_time;
}

duration<double> function_timer::end_timer()
{
    this->_end_time = high_resolution_clock::now();
    this->_duration = duration_cast<duration<double>>(this->_end_time - this->_start_time);

    return this->_duration;
}

double function_timer::get_duration()
{
    return this->_duration.count();
}

void start_timer(function_timer *timer)
{
    timer->start_timer();
    return;
}

function_timer *new_timer()
{
    function_timer *timer = new function_timer();
    if (!timer)
    {
        perror("Unable to create the timer!\n");
        return 0;
    }
    return timer;
}

double end_timer(function_timer *timer)
{
    timer->end_timer();
    return timer->get_duration();
}

void delete_timer(function_timer *timer)
{
    if (timer)
        delete timer;
}

// double time_function(void (*function)(args...))
// {
//     function(args);
// }