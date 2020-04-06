#include <cstdarg>
#include "function_timer.h"

function_timer::function_timer(void (*function)(...))
{
}

function_timer::function_timer(char *fn_name, void (*function)(...))
{
    this->_fn_name = fn_name;
}
