/* --------------------------------------------------------
 * File: NthPrimeFinder.cpp
 * --------------------------------------------------------
 * Program to print sequence of prime number
 */
 
#include <iostream>

// Function prototypes
int prime(int n);
int isPrime(int n);

int main() {
    // Loop to print the first 14 prime numbers
    for (int i = 1; i < 15; i++) {
        std::cout << i << "th number in the prime number sequence: " << prime(i) << '\n';
    }

    return 0; // Indicate successful completion
}

/* --------------------------------------------------------
 * Function: isPrime
 * Usage: isPrime(number)
 * --------------------------------------------------------
 * Function takes input number and checks wheather given 
 * number is prime or not. It returns true for prime and 
 * false for non prime number
 * ---------------------------------------------------------
 */
int isPrime(int num) {
    if (num <= 1) return false; // Numbers less than or equal to 1 are not prime
    for (int i = 2; i < num; i++) { // Check divisibility from 2 to n-1
        if (num % i == 0) {
            return false; // Return false if n is divisible by i
        }
    }
    return true; // Return true if no divisors are found
}

// Function to find the nth prime number
/* --------------------------------------------------------
 * Function: prime
 * Usage: prime(n)
 * --------------------------------------------------------
 * Function aims to find and return the nth prime number 
 * in the sequence of prime numbers.
 * ---------------------------------------------------------
 */
int prime(int n) {
    int count = 0; // Counter for the number of primes found
    int primeNum = 2; // Starting number to check for primality

    while (count < n) { // Continue until the nth prime is found
        if (isPrime(primeNum)) { // Check if the current number is prime
            count++; // Increment the count of found primes
            if (count == n) return primeNum; // Return the nth prime number
        }
        primeNum++; // Move to the next number
    }
    return -1; // Return -1 if no prime number is found (should not occur)
}
