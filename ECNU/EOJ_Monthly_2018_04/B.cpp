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

map<PII, int> M;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m, k;
    cin >> n >> m >> k;
    if (n != m) return cout << "No" << endl, 0;
    vector<int> a(n), b(n);
    for (auto& t : a) cin >> t;
    for (auto& t : b) cin >> t;
    while (k--)
    {
        static int u, v;
        cin >> u >> v;
        M[mp(u, v)] = 1, M[mp(v, u)] = 1;
    }
    for (int i = 0; i < n; i++)
        if (a[i] != b[i] && M[mp(a[i], b[i])] == 0) return cout << "No" << endl, 0;
    cout << "Yes" << endl;
    return 0;
}