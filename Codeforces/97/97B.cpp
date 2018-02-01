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

const int maxn = 1e4 + 5;
PII p[maxn];
set <PII> ans;

void dfs(int l, int r)
{
    int m = (l + r) >> 1, mid_x = p[m].X;
    for (int i = l; i <= r; i++)
        ans.insert(mp(mid_x, p[i].Y));
    if (l < m)
        dfs(l, m - 1);
    if (m < r)
        dfs(m + 1, r);
}

int main()
{
    fastin
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> p[i].X >> p[i].Y;
    sort(p, p + n);
    dfs(0, n - 1);
    cout << ans.size() << endl;
    for (set<PII>::iterator it = ans.begin(); it != ans.end(); it++)
        cout << (*it).X << " " << (*it).Y << endl;
    return 0;
}
