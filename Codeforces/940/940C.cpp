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

bool dfs(int pos, const string& a, const string& b, string& ans, bool limit, int n)
{
    if (pos == n)
    {
        if (ans <= a) return false;
        cout << ans << endl;
        return true;
    }
    for (auto& ch : b)
    {
        if (limit && pos < a.length() && ch < a[pos]) continue;
        ans.push_back(ch);
        if (pos < a.length() && dfs(pos + 1, a, b, ans, limit & ch == a[pos], n) || pos >= a.length() && dfs(pos + 1, a, b, ans, limit, n))
            return true;
        ans.pop_back();
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
    cin >> n >> k;
    string a, b, ans;
    cin >> a;
    b = a;
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    dfs(0, a, b, ans, true, k);
    return 0;
}