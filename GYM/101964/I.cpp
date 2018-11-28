#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define dbg(args...)                             \
    do                                           \
    {                                            \
        cout << "\033[32;1m" << #args << " -> "; \
        err(args);                               \
    } while (0)
#else
#define dbg(...)
#endif
void err()
{
    cout << "\033[39;0m" << endl;
}
template <template <typename...> class T, typename t, typename... Args>
void err(T<t> a, Args... args)
{
    for (auto x : a) cout << x << ' ';
    err(args...);
}
template <typename T, typename... Args>
void err(T a, Args... args)
{
    cout << a << ' ';
    err(args...);
}
/****************************************************************************************************/

const int N = 1 << 7;

template <class T>
struct BIT
{
    vector<T> bit;
    int n;
    void init(int n)
    {
        this->n = n;
        bit.assign(n + 1, 0);
    }
    void update(int x, T v)
    {
        for (; x <= n; x += x & -x) bit[x] += v;
    }
    T query(int x)
    {
        T ret = 0;
        for (; x; x -= x & -x) ret += bit[x];
        return ret;
    }
    int kth(int k)
    {
        int ret = 0, cnt = 0;
        for (int i = 20; ~i; i--)
        {
            ret ^= (1 << i);
            if (ret > n || cnt + bit[ret] >= k)
                ret ^= (1 << i);
            else
                cnt += bit[ret];
        }
        return ret + 1;
    }
};
BIT<int> T;

int a[N], d[N];

long long dp[N];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    a[0] = 105;
    T.init(n);
    for (int i = 1; i <= n; i++) T.update(i, 1);
    for (int i = 0, x, y; i < m; i++)
    {
        scanf("%d%d", &x, &y);
        if (x > y) swap(x, y);
        d[x]++;
    }
    for (int i = 1; i <= n; i++)
    {
        a[i] = T.kth(d[i] + 1);
        T.update(a[i], -1);
    }
    for (int i = 1; i <= n; i++)
    {
        int mx = 0;
        long long tmp = 0;
        for (int j = i - 1; j; j--)
        {
            if (a[j] > a[i]) continue;
            if (a[j] > mx) mx = a[j], tmp += dp[j];
        }
        dp[i] = max(1LL, tmp);
    }
    int mx = 0;
    long long ans = 0;
    for (int i = n; i; i--)
    {
        if (a[i] < mx) continue;
        mx = a[i];
        ans += dp[i];
    }
    printf("%lld\n", ans);
}