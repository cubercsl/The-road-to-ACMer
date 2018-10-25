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

const long long eps = 1e-8;
#define zero(x) ((fabs(x) < eps ? 1 : 0))
#define sgn(x) (fabs(x) < eps ? 0 : ((x) < 0 ? -1 : 1))

const int N = 1 << 17;

struct point
{
    long long x, y;
    point(long long a = 0, long long b = 0) { x = a, y = b; }
} p[N];

long long OnEdge(point p[], int n)
{
    long long ret = 0;
    for (int i = 0; i < n; i++)
        ret += __gcd(abs(p[i].x - p[(i + 1) % n].x), abs(p[i].y - p[(i + 1) % n].y));
    return ret;
}

long long InSide(point p[], int n)
{
    long long area = 0;
    for (int i = 0; i < n; i++)
        area += p[(i + 1) % n].y * (p[i].x - p[(i + 2) % n].x);
    return (abs(area) - OnEdge(p, n)) / 2 + 1;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%lld%lld", &p[i].x, &p[i].y);
    printf("%lld\n", InSide(p, n));
    return 0;
}