[![Build Status](https://travis-ci.org/kvedala/function_timer.svg?branch=master)](https://travis-ci.org/kvedala/function_timer)

# function_timer 
A wrapper around the CXX-11's `std::chrono` library with high-precision timer to measure precise 
execution times in a program. The wrapper enables direct use in C and C++ programs. 

## Compile
The module is provided with a cmake build system. The compile sequence is:
```sh
mkdir build
cd build
cmake .. [-G <Generator>] [-DCMAKE_INSTALL_PREFIX=<install path>]
cmake --build . --config [Release/Debug]
```
This builds a static library `function_timer` that can be installed to the prefix using:
```sh
cmake --install .
```

## APIs
The library, though written in C++, provides with C and a C++ interfaces.
### C
1. Include the header file `function_timer.h`
2. Create the timer pointer instance
```c
function_timer *timer = new_timer();
```
3. Start timer instance
```c
start_timer(timer);
```
4. End timer & get the duration since timer start.
```c
double duration = end_timer(timer);
```
If the `end_timer` function is called before calling the `start_timer`, the 
duration value is not guranteed to be 0 and will be invalid. There will not 
be any error messages.

5. Delete the timer instance
```c
delete_timer(timer);
```

### C++
1. Include the header file `function_timer.h`
2. Create the timer pointer instance
```cpp
function_timer *timer = new function_timer();
// or
function timer;
```
3. Start timer instance
```cpp
timer.start_timer();
```
4. End timer & get the duration since timer start.
```cpp
timer.end_timer();
double duration = timer.get_duration();
```
If the `end_timer` function is called before calling the `start_timer`, the 
duration value is not guranteed to be 0 and will be invalid. There will not 
be any error messages.

5. If instantiated as a pointer, delete the timer instance
```cpp
delete timer;   // iff timer is a pointer
```

## Examples
Two sample implementations are provided as
* `test.c` : test case in C
* `test.cpp` : test case in C++

## Note
To compile with C++, must enable the CXX-11 standard to account for `std::chrono` library. 
