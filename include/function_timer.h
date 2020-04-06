/**
 * @file function_timer.h
 * @author Krishna Vedala
 * @brief Provides wrappers around C++ high-precesion timer from "std::chrono"
 *  to C and C++ as a library. The duration is made available in double point
 *  precision.
 **/
#ifndef __FUNCTION_TIMER_H
#define __FUNCTION_TIMER_H

#ifdef __cplusplus
#include <chrono>
#include <ctime>
#include <cstdarg>

using namespace std::chrono;

/** @addtogroup CPP
 * {
 **/
/**
 * declare class structure for convenience
 **/
class function_timer
{
public:
    function_timer(){}; /**< create a new instance */

    /** start timer measurement */
    high_resolution_clock::time_point start_timer();

    /** end timer measurement */
    duration<double> end_timer();

    /** convenience to get timer duration */
    double get_duration();

private:
    // char *_fn_name = 0;
    high_resolution_clock::time_point _start_time;
    high_resolution_clock::time_point _end_time;
    duration<double> _duration;
};

/**
 * }
 **/

extern "C"
{
#else // __cplusplus
#include <stdarg.h>
typedef struct function_timer function_timer;
#endif // __cplusplus

    /** @addtogroup C
     **/
    /**
     * function to create a new timer instance to use in C programs
     * @note The instantiated timer need to be explicitly deleted!
     **/
    extern function_timer *new_timer(void);

    /**
     * function to start the timer in C programs.
     * Requires timer to be created using the function `new_timer`
     **/
    extern void start_timer(function_timer *timer);

    /**
     * function to end the timer in C programs.
     * Requires timer to be created using the function `new_timer`. If the
     * function `start_timer` was not called before, the duration will be
     * inavlid.
     **/
    extern double end_timer(function_timer *timer);

    /**
     * function to delete a timer instance
     * @note The timer should be instantiated using the function `new_timer`
     **/
    extern void delete_timer(function_timer *timer);
    // extern double time_function(void (*function)(...));

    /**
     * }
     **/

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __FUNCTION_TIMER_H