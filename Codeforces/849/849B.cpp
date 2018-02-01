#include <bits/stdc++.h>
using namespace std;
#define clr(a,x) memset(a, x, sizeof(a))
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;

const int maxn = 1005;
pair<ll, ll> P[maxn];
int n;
bool vis[maxn];

bool check1()
{
    ll d = P[2].Y - P[1].Y;
    clr(vis, 0);
    vis[1] = vis[2] = 1;
    for (int i = 3; i <= n; i++)
        if (P[1].Y + (i - 1)*d == P[i].Y)
            vis[i] = 1;
    int p = 1;
    while (vis[p]) p++;
    if (p == n + 1) return false;
    vis[p] = 1;
    for (int i = p + 1; i <= n; i++)
        if (vis[i] == 0 && P[p].Y + (i - p)*d == P[i].Y)
            vis[i] = 1;
    for (int i = 1; i <= n; i++)
        if (vis[i] == 0)
            return false;
    return true;
}
bool check2()
{
    double d = (P[3].Y - P[1].Y) / 2.0;
    clr(vis, 0);
    vis[1] = vis[3] = 1;
    for (int i = 4; i <= n; i++)
        if (abs(P[1].Y + (i - 1)*d - P[i].Y) < eps)
            vis[i] = 1;
    int p = 1;
    while (vis[p]) p++;
    if (abs(P[2].Y - P[1].Y - d) < eps) return false;
    vis[p] = 1;
    for (int i = p + 1; i <= n; i++)
        if (vis[i] == 0 && abs(P[p].Y + (i - p)*d - P[i].Y) < eps)
            vis[i] = 1;
    for (int i = 1; i <= n; i++)
        if (vis[i] == 0)
            return false;
    return true;
}
bool check3()
{
    ll d = P[3].Y - P[2].Y;
    clr(vis, 0);
    vis[2] = vis[3] = 1;
    for (int i = 4; i <= n; i++)
        if (P[2].Y + (i - 2)*d == P[i].Y)
            vis[i] = 1;
    int p = 1;
    vis[p] = 1;
    if (P[2].Y - P[1].Y == d) return false;
    for (int i = p + 1; i <= n; i++)
        if (vis[i] == 0 && P[p].Y + (i - p)*d == P[i].Y)
            vis[i] = 1;

    for (int i = 1; i <= n; i++)
        if (vis[i] == 0)
            return false;
    return true;
}
int main()
{
    while (cin >> n)
    {
        for (int i = 1; i <= n; i++)
        {
            cin >> P[i].Y;
            P[i].X = i;
        }
        if (check1() || check2() || check3())
        {
            puts("Yes");
            continue;
        }
        puts("No");
    }

    return 0;
}
