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

const int maxn = 1 << 17;
int a[maxn];
vector<int> G[maxn];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin int n, k, m;
    while (cin >> n >> k >> m)
    {
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < k; i++)
            G[i].clear();
        if (m == 1)
        {
            cout << "Yes" << endl;
            for (int i = 0; i < k; i++)
            {
                if (i) cout << " ";
                cout << a[i];
            }
            cout << endl;
            continue;
        }
        bool flag = 0;
        for (int i = 0; i < n; i++)
            G[a[i] % m].pb(i);
        for (int i = 0; i < k; i++)
        {
            if (G[i].size() >= k)
            {
                cout << "Yes" << endl;
                for (int j = 0; j < k; j++)
                {
                    if (j) cout << " ";
                    cout << a[G[i][j]];
                }
                cout << endl;
                flag = 1;
                break;
            }
        }
        if (!flag) cout << "No" << endl;
    }
    return 0;
}
