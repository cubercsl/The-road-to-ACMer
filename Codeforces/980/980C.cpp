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

const int N = 1 << 17;

int id[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    clr(id, -1);
    int n, k;
    cin >> n >> k;
    for (int i = 0, x; i < n; i++)
    {
        cin >> x;
        if (~id[x])
        {
            cout << id[x] << " ";
            continue;
        }
        int p = x;
        for (int j = 0; j < k && ~p; j++, p--)
            if (~id[p]) break;
        if (x - id[p] < k)
        {
            for (int jj = id[p]; jj <= x; jj++) id[jj] = id[p];
            cout << id[x] << " ";
            continue;
        }
        p++;
        for (int j = p; j <= x; j++) id[j] = p;
        cout << id[x] << " ";
    }
    return 0;
}