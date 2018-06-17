#include <bits/stdc++.h>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;

int n, m;
vector<PII> aa, bb;
int a, b;

bool check(int aa, int bb, vector<PII>& op)
{
    set<int> s;
    for (int i = 0; i < op.size(); i++)
    {
        PII vv = op[i];
        if (vv.X == aa && vv.Y == bb)
            continue;
        if (vv.X == aa || vv.Y == bb || vv.X == bb || vv.Y == aa)
        {
            if (vv.X == aa || vv.Y == aa)
                s.insert(aa);
            else
                s.insert(bb);
        }
    }
    if (s.size() == 1)
        return true;
    else if (s.size() == 0)
        return false;
    cout << -1;
    exit(0);
    return false;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    set<int> ans;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &a, &b);
        if (a > b) swap(a, b);
        aa.push_back({a, b});
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &a, &b);
        if (a > b) swap(a, b);
        bb.push_back({a, b});
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (aa[i].X == bb[j].X && aa[i].Y == bb[j].Y)
                continue;
            if (check(aa[i].X, aa[i].Y, bb) && check(bb[j].X, bb[j].Y, aa))
                if (aa[i].X == bb[j].X || aa[i].Y == bb[j].Y || aa[i].Y == bb[j].X || aa[i].X == bb[j].Y)
                {
                    if (aa[i].X == bb[j].X || aa[i].X == bb[j].Y)
                        ans.insert(aa[i].X);
                    else
                        ans.insert(aa[i].Y);
                }
        }
    }
    if (ans.size() == 1)
        cout << *ans.begin();
    else if (ans.size() > 0)
        cout << 0;
    else
        cout << -1;
}
