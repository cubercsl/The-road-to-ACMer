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

const int N = 1 << 18;
int vec[N];
const int mod = 119 << 23 | 1;
typedef long long ll;
int k;
ll Pow(ll a, ll n)
{
    ll t = 1;
    for (; n; n >>= 1, (a *= a) %= mod)
        if (n & 1) (t *= a) %= mod;
}
ll gao(int l, int r, int c)
{
    if (l == 0 && r == 0) return Pow(k - 1, c - 1) * k % mod;
    if (l == 0 || r == 0) return Pow(k - 1, c) % mod;
    if (c == 0) return l == 0 || l != r;
}

long long solve(const vector<int>& a)
{
    int n = a.size();
    f
}

int main()
{
    int n;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", vec + i);
    vector<int> a, b;
    for (int i = 0; i < n; i += 2) a.push_back(vec[i]);
    for (int i = 1; i < n; i += 2) b.push_back(vec[i]);
    long long ans = solve(a) * solve(b) % mod;
    printf("%lld\n", ans);
    return 0;
}