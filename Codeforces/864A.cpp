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

const int maxn = 105;
int vis[maxn];

int main()
{
#ifndef ONLINE_JUDGE
// freopen("1.in", "r", stdin);
// freopen("1.out", "w", stdout);
#endif
    int n;
    int a[105];
    while (cin >> n)
    {
        vector<int> v;
        clr(vis, 0);
        int num;
        for (int i = 0; i < n; i++)
        {
            cin >> num;
            vis[num]++;
        }
        int cnt = 0;
        int tot = 0;
        bool flag = 0;
        for (int i = 0; i <= 100; i++)
            if (vis[i])
            {
                a[tot++] = vis[i];
                cnt++;
                v.pb(i);
            }
        if (cnt != 2)
            cout << "NO" << endl;
        else if (a[0] == a[1])
        {
            cout << "YES" << endl;
            for (int i = 0; i < v.size(); i++)
            {
                if (i) cout << " ";
                cout << v[i];
            }
            cout << endl;
        }
        else
            cout << "NO" << endl;
    }
    return 0;
}
