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

const int maxn = 20005;
int a[maxn];
vector<int> v[maxn];

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            v[i].clear();
            cin >> a[i];
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= (n - 1) / i; j++)
                v[i].pb(a[i * j]);
            sort(v[i].begin(), v[i].end(), cmp);
        }
        while (m--)
        {
            int k, s;
            cin >> k >> s;
            if (k >= n)
                if (s == 1)
                    cout << a[0] << endl;
                else
                    cout << -1 << endl;
            else if (s > v[k].size())
                cout << -1 << endl;
            else
                cout << v[k][s - 1] << endl;
        }
    }
    return 0;
}
