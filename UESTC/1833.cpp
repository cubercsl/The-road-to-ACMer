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

bool dfs(int cur, const vector<int>& a, int mo, vector<int>& ans)
{
    if (cur == ans.size()) return mo == 0;
    for (auto& t : a)
    {
        if (cur == 0 && cur + 1 != ans.size() && t == 0) continue;
        if (dfs(cur + 1, a, (mo + t) % 3, ans))
        {
            ans[cur] = t;
            return true;
        }
    }
    return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, k;
    while (~scanf("%d%d", &n, &k))
    {
        vector<int> a(n), m(3);
        for (auto& t : a) scanf("%d", &t);
        sort(a.begin(), a.end(), greater<int>());
        for (auto& t : a) m[t % 3]++;
        int cnt = 0;
        for (auto& t : m) cnt += t != 0;
        if (cnt == 1)
        {
            if (k == 1 && a[0] % 3 == 0)
                printf("%d", a[0]);
            else if (a[0] != 0 && k * a[0] % 3 == 0)
                for (int i = 0; i < k; i++) printf("%d", a[0]);
            else
                printf("%d", -1);
            puts("");
            continue;
        }
        vector<int> ans(k);
        for (int i = 0; i < k - 3; i++) ans[i] = a[0];
        int s = max(0, k - 3);
        int mo = s * a[0];
        if (dfs(s, a, mo, ans))
            for (auto& t : ans) printf("%d", t);
        else
            printf("%d", -1);
        puts("");
    }
    return 0;
}