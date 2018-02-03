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

const int N = 1e6 + 5;
ll ans[N];
int fail[N << 1], id[N], len[N];

void get_fail(const string& s)
{
    int m = s.length();
    int i = 0, j = fail[0] = -1;
    while (i < m)
    {
        while (j != -1 && s[i] != s[j]) j = fail[j];
        fail[++i] = ++j;
    }
}
int KMP(const string& y, const string& x)
{
    int m = x.length(), n = y.length();
    int i = 0, j = 0, ans = 0;
    while (i < n)
    {
        while (j != -1 && y[i] != x[j]) j = fail[j];
        i++, j++;
        if (j >= m) ans++, j = fail[j];
    }
    return ans;
}

string s[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < n; i++) len[i] = s[i].length(), id[i] = i;
    sort(id, id + n, [](int a, int b) { return len[a] < len[b]; });
    for (int i = 0; i < n; i++)
    {
        if (len[id[i]] > len[id[0]]) break;
        if (i > 0)
        {
            if (s[id[i]] == s[id[0]]) ans[id[i]] = ans[id[0]];
        }
        else
        {
            ans[id[i]] = 1;
            get_fail(s[id[i]]);
            for (int j = 0; j < n; j++) (ans[id[i]] *= KMP(s[j], s[id[i]])) %= mod;
        }
    }
    for (int i = 0; i < n; i++) cout << ans[i] << '\n';
    return 0;
}
