#include <iostream>
#include <iomanip>
#include "function_timer.h"

#ifdef _OPENMP
#include <omp.h>
#endif

/**
 * Function to check if a given number is prime or not
 **/
char is_prime(long n)
{
    for (long i = 2; i * i <= n + 1; i++)
        if (n % i == 0)
            return 0;

    return 1;
}

/**
 * Function to find sum of all prime numbers less than N
 **/
long long sum_of_primes(long N)
{
    long long sum = 2;

    for (long i = 3; i < N; i += 2) // skip even numbers
        if (is_prime(i))
            sum += i;

    return sum;
}

#ifdef _OPENMP
/**
 * Function to find sum of all prime numbers less than N
 * Parallelized by OpenMP
 **/
long long sum_of_primes_omp(long N)
{
    long long sum = 2;

#pragma omp parallel for reduction(+ \
                                   : sum)
    for (long i = 3; i < N; i += 2) // skip even numbers
        if (is_prime(i))
            sum += i;

    return sum;
}
#endif

int main(int argc, char **argv)
{
    using namespace std;
    cout << scientific;
    setprecision(4);

    function_timer timer; // created on heap so no need to delete

    long n = 100;
    timer.start_timer();
    long long sum = sum_of_primes(n);
    timer.end_timer();
    cout << setw(6) << n << ": " << sum << endl;
    cout << "Time taken: " << timer.get_duration() << " sec" << endl
         << endl;

    n = 1000;
    timer.start_timer();
    sum = sum_of_primes(n);
    timer.end_timer();
    cout << setw(6) << n << ": " << sum << endl;
    cout << "Time taken: " << timer.get_duration() << " sec" << endl
         << endl;

    n = 10000;
    timer.start_timer();
    sum = sum_of_primes(n);
    timer.end_timer();
    cout << setw(6) << n << ": " << sum << endl;
    cout << "Time taken: " << timer.get_duration() << " sec" << endl
         << endl;

    n = 100000;
    timer.start_timer();
    sum = sum_of_primes(n);
    timer.end_timer();
    cout << setw(6) << n << ": " << sum << endl;
    cout << "Time taken: " << timer.get_duration() << " sec" << endl
         << endl;

#ifdef _OPENMP
    cout << "Using parallelization:" << endl;
    n = 100000;
    timer.start_timer();
    sum = sum_of_primes_omp(n);
    timer.end_timer();
    cout << setw(6) << n << ": " << sum << endl;
    cout << "Time taken: " << timer.get_duration() << " sec" << endl
         << endl;
#endif
    return 0;
}
