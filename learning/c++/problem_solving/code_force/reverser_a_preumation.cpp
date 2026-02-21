#include <bits/stdc++.h>

using namespace std;

auto fast_io = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

int calculate_permutation(int x, int y) 
{
    int count = 0;
    for (int i = x; i < y; i++) 
        count += i;
    return count;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        int l = 0, r = n - 1;
        
        
    }
    return 0;
}