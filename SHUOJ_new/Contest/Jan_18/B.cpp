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

void dfs(int id, const VI& v, set<int>& sum, int cur = 0)
{
    if (id == v.size()) return;
    dfs(id + 1, v, sum, cur); // 不选
    sum.insert(cur + v[id]);
    dfs(id + 1, v, sum, cur + v[id]); // 选
}

int solve(const set<int>& sum)
{
    for (int i = 1;; i++)
        if (sum.find(i) == sum.end()) return i;
    assert(false);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    while (cin >> n, n)
    {
        vector<int> v(n);
        for (auto& num : v) cin >> num;
        set<int> sum;
        dfs(0, v, sum);
        cout << solve(sum) << endl;
    }
    return 0;
}
