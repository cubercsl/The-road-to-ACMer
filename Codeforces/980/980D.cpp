#pragma GCC optimize(3)
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

const int N = 1 << 14;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin
    vector<int> p;
    bool vis[N] = {1, 1};
    for (int i = 2; i < N; i++)
    {
        if (!vis[i]) p.push_back(i);
        for (auto& t : p)
        {
            if (t > N / i) break;
            vis[t * i] = true;
            if (i % t == 0) break;
        }
    }
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& t : v) cin >> t;
    for (auto& t : v)
        if (t)
            for (auto& d : p)
                while (t % (d * d) == 0) t /= (d * d);
    vector<int> ans(n);
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        s.clear();
        for (int j = i; j < n; j++)
        {
            if (v[j])
                s.insert(v[j]);
            ans[max(0, (int)s.size() - 1)]++;
        }
    }
    for (auto& t : ans) cout << t << " ";
    return 0;
}