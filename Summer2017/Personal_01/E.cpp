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
PII node[maxn];
bool cmp(PII a, PII b)
{
    return a.Y - a.X > b.Y - b.X;
}

int main()
{
#ifndef ONLINE_JUDGE
    // freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        int v, n;
        bool flag = true;
        cin >> v >> n;
        for (int i = 0; i < n; i++)
            cin >> node[i].X >> node[i].Y;
        sort(node, node + n, cmp);
        for (int i = 0; i < n; i++)
        {
            if (node[i].Y > v)
            {
                flag = false;
                break;
            }
            v -= node[i].X;
        }
        if (flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}
