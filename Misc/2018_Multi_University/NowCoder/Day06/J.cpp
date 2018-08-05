#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
unsigned int x, y, z;

unsigned int tang()
{
    unsigned int t;
    x ^= x << 16;
    x ^= x >> 5;
    x ^= x << 1;
    t = x;
    x = y;
    y = z;
    z = t ^ x ^ y;
    return z;
}

inline ull lcm(ull x, ull y)
{
    return x / __gcd(x, y) * y;
}

int main()
{
    int T, kase = 0;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        long long a, b, c;
        scanf("%d%lld%lld%lld", &n, &a, &b, &c);
        x = a, y = b, z = c;
        vector<ull> v(n);
        for (int i = 0; i < n; i++) v[i] = tang();
        int t = min(n, 20);
        nth_element(v.begin(), v.begin() + t, v.end(), greater<ull>());
        ull ans = 0;
        for (int i = 0; i < t; i++)
            for (int j = 0; j < i; j++)
                ans = max(ans, lcm(v[i], v[j]));
        printf("Case #%d: %llu\n", ++kase, ans);
    }
}