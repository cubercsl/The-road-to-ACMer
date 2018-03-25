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

const int maxn = 1e6 + 5;
struct Trie
{
    int ch[maxn][26];
    int val[maxn];
    int rt, sz, cnt;
    int newnode()
    {
        clr(ch[sz], -1), val[sz] = 0;
        return sz++;
    }
    void init() { sz = cnt = 0, rt = newnode(); }
    void insert(const string& s)
    {
        int u = rt;
        for (auto& t : s)
        {
            int c = t - 'A';
            if (ch[u][c] == -1) ch[u][c] = newnode();
            u = ch[u][c];
        }
        if (val[u] == 0) cnt++;
        val[u]++;
    }
} ans;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin int n;
    cin >> n;
    ans.init();
    string s;
    while (n--)
    {
        cin >> s;
        int c = s[0] - 'A';
        for (auto& t : s)
        {
            t -= c;
            if (t < 'A') t += 26;
        }
        // cout << s << endl;
        ans.insert(s);
    }
    cout << ans.cnt << endl;
    return 0;
}