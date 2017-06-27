#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 5;
const int mod = 1e9 + 7;
long long a[maxn];
long long fastpow(long long b)
{
    long long r = 1, base = 2;
    while (b)
    {
        if (b & 1)
            r = r * base % mod;
        base = base * base % mod;
        b >>= 1;
    }
    return r - 1;
}

int main()
{
    int n;
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        long long ans = 0;
        for (int i = 0; i < n; i++)
            ans = (ans + a[i] * (fastpow(i) - fastpow(n - 1 - i))) % mod;
        cout << (ans + mod) % mod << endl;
    }
    return 0;
}
