#include <bits/stdc++.h>
using namespace std;

// fast I/O
auto fast_io = []() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

int main() 
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, q;
        cin >> n >> q;

        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        // preprocess from right to left
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] < b[i]) a[i] = b[i];
            if (i > 0 && a[i - 1] < a[i]) a[i - 1] = a[i];
        }

        // prefix sum
        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; i++)
            pref[i + 1] = pref[i] + a[i];

        while (q--) {
            int l, r;
            cin >> l >> r;
            cout << pref[r] - pref[l - 1] << '\n';
        }
    }
    return 0;
}