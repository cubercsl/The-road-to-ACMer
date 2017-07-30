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

const int maxn = 20;
int n, m;
int ans;
int a[maxn];

void dfs(int i, int now , int dep)
{
    if (dep == m)
    {
        ans = max(ans, now);
        return;
    }
    if (i == n)
        return;
    dfs(i + 1, now * a[i], dep + 1);
    dfs(i + 1, now, dep);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        ans = -INF;
        dfs(0, 1, 0);
        cout << ans << endl;
    }
    return 0;
}
