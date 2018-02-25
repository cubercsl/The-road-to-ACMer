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

int gao(int n, vector<int> a)
{
    int now = n;
    for (auto& t : a) now = now * (100 - t) / 100;
    return n - now;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    vector<int> a(3);
    cin >> n;
    int ans = 0;
    for (auto& t : a) cin >> t;
    do
        ans = max(ans, gao(n, a));
    while (next_permutation(a.begin(), a.end()));
    cout << ans << endl;
    return 0;
}