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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (auto& t : v) cin >> t;
    vector<int> k(m + 1);
    for (int i = 1; i <= m; i++) cin >> k[i];
    for (int i = 0; i < n; i++)
    {
        vector<int> cnt(m + 1);
        for (int j = i; j < n; j++)
        {
            cnt[v[j]]++;
            if (cnt == k) return cout << "YES", 0;
        }
    }
    cout << "NO";
    return 0;
}