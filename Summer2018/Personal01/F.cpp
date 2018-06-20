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

typedef unsigned long long ull;
const int N = 1 << 18;
namespace Hash
{
ull p[N];
const static ull mod = 1e9 + 7;
void init()
{
    p[0] = 1;
    for (int i = 1; i < N; i++) p[i] = p[i - 1] * mod;
}
vector<ull> make(const string& s)
{
    int n = s.length();
    vector<ull> v(n + 1);
    for (int i = 1; i <= n; i++) v[i] = v[i - 1] * mod + s[i - 1];
    return v;
}
ull get(int l, int r, const vector<ull>& h) { return h[r] - h[l] * p[r - l]; }
ull get(const char* s)
{
    ull ret = 0;
    for (int i = 0; s[i]; i++) (ret *= mod) += s[i];
    return ret;
}
}; // namespace Hash

char buf[N];

struct Node
{
    int x, y;
    bool operator<(const Node& rhs) const
    {
        return x > rhs.x || x == rhs.x && y < rhs.y;
    }
} dp[N][30];

int rmq(int l, int r)
{
    int k = 31 - __builtin_clz(r - l + 1);
    return min(dp[l][k], dp[r - (1 << k) + 1][k]).y;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    Hash::init();
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, q;
        scanf("%d%d", &n, &q);
        unordered_map<ull, int> dic;
        for (int i = 1; i <= n; i++)
        {
            scanf("%s", buf);
            string s(buf);
            int m = s.length();
            dic[Hash::get(buf)] = i;
            vector<ull> a = Hash::make(s);
            reverse(s.begin(), s.end());
            vector<ull> b = Hash::make(s);
            int cnt = 0;
            for (int i = 0; i < m; i++)
                for (int j = i + 1; j < m + 1; j++)
                {
                    ull aa = Hash::get(i, j, a);
                    ull bb = Hash::get(m - j, m - i, b);
                    // cerr << aa << " " << bb << endl;
                    if (aa == bb) cnt++;
                }
            dp[i][0] = {cnt, i};
            cerr << cnt << endl;
        }
        for (int j = 1; (1 << j) <= n; j++)
            for (int i = 1; i + (1 << j) - 1 <= n; i++)
                dp[i][j] = min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
        while (q--)
        {
            static int l, r;
            scanf("%s", buf);
            l = dic[Hash::get(buf)];
            scanf("%s", buf);
            r = dic[Hash::get(buf)];
            if(l > r) swap(l, r);
            printf("%d\n", rmq(l, r));
        }
    }
    return 0;
}
