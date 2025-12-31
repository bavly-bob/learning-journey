// Easy Number Challenge
// Problem Link: https://codeforces.com/problemset/problem/577/A
// Description: This program calculates the sum of the number of divisors of the product of all combinations of three integers i, j, and l, where 1 <= i <= n, 1 <= j <= m, and 1 <= l <= k.
// It uses a function to count the divisors of a number based on its prime factorization.

#include <iostream>

int countDivisors(int n)
{
    int ans = 1;
    for(int p = 2; p * p <= n; p++)
    {
        if(n % p == 0)
        {
            int cnt = 0;
            while(n % p == 0)
            {
                n /= p;
                cnt++;
            }
            ans *= (cnt + 1);
        }
    }
    if(n > 1)  // remaining prime
        ans *= 2;

    return ans;
}

int main()
{
    int n , m , k;
    std::cin >> n >> m >> k;
    
    int sum_divisors = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            for(int l = 1; l <= k; l++)
            {
                int prod = i * j * l;
                sum_divisors += countDivisors(prod);
            }
    std::cout << sum_divisors << std::endl;
    return 0;
}