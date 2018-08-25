#include <bits/stdc++.h>
using namespace std;

template <class T>
void fwt(vector<T>& f, int m)
{
    int n = __builtin_ctz(m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (j & (1 << i))
            {
                int l = f[j ^ (1 << i)], r = f[j];
                f[j ^ (1 << i)] = l + r, f[j] = l - r;
            }
}

template <class T>
void ifwt(vector<T>& f, int m)
{
    int n = __builtin_ctz(m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (j & (1 << i))
            {
                int l = f[j ^ (1 << i)], r = f[j];
                f[j ^ (1 << i)] = (l + r) >> 1, f[j] = (l - r) >> 1;
            }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    int sum = 0;
    vector<int> a(1 << 19), b(1 << 19);
    for (int i = 0, x; i < n; i++)
    {
        scanf("%d", &x);
        a[x] = b[x] = 1;
        sum ^= x;
    }
    if (sum == 0) return printf("%d\n", n), 0;
    a[0] = b[0] = 1;
    fwt(b, b.size());
    while (a[sum] == 0)
    {
        n--;
        fwt(a, a.size());
        for (int i = 0; i < (1 << 19); i++) a[i] *= b[i];
        ifwt(a, a.size());
        for (int i = 0; i < (1 << 19); i++) a[i] = (a[i] != 0);
    }
    printf("%d\n", n - 1);
    return 0;
}