#include <stdio.h>
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
    function_timer *timer = new_timer();
    if (timer == 0)
        return -1;

    long n = 100;
    start_timer(timer);
    long long sum = sum_of_primes(n);
    double duration = end_timer(timer);
    printf("%6ld: %8lld\n", n, sum);
    printf("Time taken: %.4g sec\n\n", duration);

    n = 1000;
    start_timer(timer);
    sum = sum_of_primes(n);
    duration = end_timer(timer);
    printf("%6ld: %8lld\n", n, sum);
    printf("Time taken: %.4g sec\n\n", duration);

    n = 10000;
    start_timer(timer);
    sum = sum_of_primes(n);
    duration = end_timer(timer);
    printf("%6ld: %8lld\n", n, sum);
    printf("Time taken: %.4g sec\n\n", duration);

    n = 100000;
    start_timer(timer);
    sum = sum_of_primes(n);
    duration = end_timer(timer);
    printf("%6ld: %8lld\n", n, sum);
    printf("Time taken: %.4g sec\n\n", duration);

#ifdef _OPENMP
    n = 100000;
    printf("Using OpenMP paralleization\n");
    start_timer(timer);
    sum = sum_of_primes_omp(n);
    duration = end_timer(timer);
    printf("%6ld: %8lld\n", n, sum);
    printf("Time taken: %.4g sec\n\n", duration);
#endif

    delete_timer(timer);

    return 0;
}
