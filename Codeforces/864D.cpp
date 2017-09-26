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

const int maxn = 2e5 + 5;
int a[maxn];
int vis[maxn];
bool flag[maxn];
int v[maxn];

int main()
{
#ifndef ONLINE_JUDGE
// freopen("1.in", "r", stdin);
// freopen("1.out", "w", stdout);
#endif
    int n;
    while (cin >> n)
    {
        clr(vis, 0);
        clr(flag, 0);
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            vis[a[i]]++;
        }
        int sum = 0, p = 0;
        for (int i = 1; i <= n; i++)
            if (vis[i] == 0)
                v[p++] = i;
            else if (vis[i] > 1)
                sum += vis[i] - 1;
        cout << sum << endl;
        p = 0;
        for (int i = 1; i <= n; i++)
        {
            if (vis[a[i]] == 1)
                if (!flag[a[i]])
                    flag[a[i]] = 1, cout << a[i];
                else
                    cout << v[p++];
            else
            {
                vis[a[i]]--;
                if (!flag[a[i]])
                    if (a[i] > v[p])
                        cout << v[p++];
                    else
                        cout << a[i], flag[a[i]] = 1;
                else
                    cout << v[p++];
            }
            if (i != n) cout << " ";
        }
        cout << endl;
    }
    return 0;
}
