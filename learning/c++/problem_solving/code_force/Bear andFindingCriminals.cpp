// https://codeforces.com/contest/680/problem/B
/*
There are n cities in Bearland, numbered 1 through n. Cities are arranged in one long row. The distance between cities i and j is equal to |i - j|.

Limak is a police officer. He lives in a city a. His job is to catch criminals. It's hard because he doesn't know in which cities criminals are. Though, he knows that there is at most one criminal in each city.

Limak is going to use a BCD (Bear Criminal Detector). The BCD will tell Limak how many criminals there are for every distance from a city a. After that, Limak can catch a criminal in each city for which he is sure that there must be a criminal.

You know in which cities criminals are. Count the number of criminals Limak will catch, after he uses the BCD.

Input
The first line of the input contains two integers n and a (1 ≤ a ≤ n ≤ 100) — the number of cities and the index of city where Limak lives.

The second line contains n integers t1, t2, ..., tn (0 ≤ ti ≤ 1). There are ti criminals in the i-th city.

Output
Print the number of criminals Limak will catch.
*/ 

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a;
    cin >> n >> a;
    a--;
    vector<int> arr(n);
    int count = 0;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    for (int d = 0; d < n; d++) 
    {
        int left = a - d;
        int right = a + d;
        
        if (left >= 0 && right < n) 
        {
            if (left == right && arr[left]) 
                count++; 
            else if (arr[left] && arr[right])
                count += 2;
        } 
        else if (left >= 0 && arr[left]) 
            count++;
        else if (right < n && arr[right]) 
            count++;
    }

    cout << count << '\n';
    
    return 0;
}