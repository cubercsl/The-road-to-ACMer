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
void merge(int l, int r, int from, int to, int& res)
{

    if (res <= 0 || l + 1 == r)
    {
        for (int i = l, j = from; i <= r; i++, j++)
            a[i] = j;
        return;
    }
    res -= 2;
    int m = (l + r) >> 1;
    int mid = (from + to + 1) >> 1;
    merge(l, m, mid, to, res);
    merge(m, r, from, mid, res);
}

int main()
{
#ifndef ONLINE_JUDGE
    // freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
#endif
    int n, k;
    while (cin >> n >> k)
    {
        k--;
        merge(0, n, 0, n, k);
        if (k)
            cout << -1 << endl;
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (i) cout << " ";
                cout << a[i] + 1;
            }
            cout << endl;
        }
    }
    return 0;
}
