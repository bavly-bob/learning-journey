// prime_checker.cpp
// This program checks if a given number is prime using the
// Miller-Rabin probabilistic primality test. It can handle large integers
// efficiently by using modular exponentiation.
// disclaimer: this code was by the help of chatgpt

#include <iostream>
#include <cmath>
#include <random>  
using namespace std;

long long modexp(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1)  // if odd
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

bool isPrime(long long n, int rounds = 5) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    long long d = n - 1;
    int k = 0;
    while (d % 2 == 0) {
        d /= 2;
        k++;
    }
    long long m = d;

    random_device rd;
    mt19937_64 gen(rd());
    uniform_int_distribution<long long> dist(2, n - 2);

    for (int r = 0; r < rounds; r++) {
        long long a = dist(gen);
        long long b = modexp(a, m, n);

        if (b == 1 || b == n - 1) continue;

        bool passed = false;
        for (int i = 1; i < k; i++) {
            b = (1LL * b * b) % n;
            if (b == n - 1) { passed = true; break; }
            if (b == 1) return false;
        }
        if (!passed) return false; // definitely composite
    }
    return true; // probably prime
}


int main() {
    long long num;
    cout << "Enter a number: ";
    cin >> num;

    if (isPrime(num))
        cout << num << " is a prime number." << endl;
    else
        cout << num << " is not a prime number." << endl;

    return 0;
}
