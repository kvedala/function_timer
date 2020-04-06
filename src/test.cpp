#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "function_timer.h"

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

int main(int argc, char **argv)
{
    using namespace std;

    long n = 100;

    if (argc == 2)         // if command line argument is provided
        n = atol(argv[1]); // use that as the upper limit

    long long sum = sum_of_primes(n);
    cout << setw(6) << n << ": " << setw(8) << sum << endl;

    n = 1000;
    sum = sum_of_primes(n);
    cout << setw(6) << n << ": " << setw(8) << sum << endl;

    n = 10000;
    sum = sum_of_primes(n);
    cout << setw(6) << n << ": " << setw(8) << sum << endl;

    return 0;
}
