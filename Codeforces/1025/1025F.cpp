#include <bits/stdc++.h>
using namespace std;
const double Pi = acos(-1.0);
#define MAXN 3010
struct Point
{
    int x, y;
    double angle;
    Point() {}
    Point(int x, int y) : x(x), y(y) {}
    Point operator-(const Point& a) const
    {
        return Point(x - a.x, y - a.y);
    }
    inline void GetAngle(const Point& a)
    {
        angle = atan2(a.y, a.x);
        if (angle <= 0.0) angle += Pi;
        return;
    }
    bool operator<(const Point& a) const
    {
        return angle < a.angle;
    }
} O;

int n, pt;
long long ans, cnt[2][3];
bool type[MAXN];
pair<Point, int> src[MAXN], P[MAXN];

inline long long Calculate(int x, bool kind)
{
    return cnt[kind][0] * (cnt[kind][0] - 1) / 2;
}

inline void Analyze(int x)
{
    memset(cnt, 0, sizeof cnt);
    pt = 0;
    O = src[x].first;
    for (int i = 1; i <= n; i++)
        if (i != x) P[++pt] = src[i];
    for (int i = 1; i < n; i++) P[i].first.GetAngle(P[i].first - O);
    sort(P + 1, P + n);
    for (int i = 1; i < n; i++)
        if (P[i].first.y < O.y || (P[i].first.y == O.y && P[i].first.x > O.x))
            cnt[type[i] = false][P[i].second]++;
        else
            cnt[type[i] = true][P[i].second]++;
    for (int i = 1; i < n; i++)
    {
        cnt[type[i]][P[i].second]--;
        ans += Calculate(src[x].second, false) * Calculate(P[i].second, true);
        ans += Calculate(src[x].second, true) * Calculate(P[i].second, false);
        cnt[type[i] ^= 1][P[i].second]++;
    }
    return;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d%d", &src[i].first.x, &src[i].first.y), src[i].second = 0;
    for (int i = 1; i <= n; i++) Analyze(i);
    printf("%lld\n", ans >> 2LL);
    return 0;
}