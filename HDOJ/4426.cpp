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
const int mod = 777777777;
const double eps = 1e-6;

const int N = 100005;
ll Pow[N];

struct Palindromic_Tree
{
    int ch[N][26], f[N], len[N], s[N];
    char str[N];
    ll cnt[N], val[N][20], v[20][26], k[20];
    int last, sz, n, m;
    int newnode(int x)
    {
        clr(ch[sz], 0), clr(val[sz], 0);
        cnt[sz] = 0, len[sz] = x;
        return sz++;
    }
    void init(int m)
    {
        this->m = m;
        sz = 0;
        newnode(0), newnode(-1);
        last = 0, n = 0, s[0] = -1, f[0] = 1;
    }
    int get_fail(int u)
    {
        while (s[n - len[u] - 1] != s[n]) u = f[u];
        return u;
    }
    void add(int c)
    {
        s[++n] = c;
        int u = get_fail(last);
        if (!ch[u][c])
        {
            int np = newnode(len[u] + 2);
            for (int i = 0; i < m; i++)
                val[np][i] = (val[u][i] + (Pow[len[u] + 1 >> 1] * v[i][c]) % mod) % mod;
            f[np] = ch[get_fail(f[u])][c];
            ch[u][c] = np;
        }
        last = ch[u][c];
        cnt[last]++;
    }
    void count()
    {
        for (int i = sz - 1; ~i; i--) cnt[f[i]] += cnt[i];
    }
    void work()
    {
        scanf("%s", str);
        for (int i = 0; i < m; i++)
        {
            scanf("%lld", &k[i]);
            for (int j = 0; j < 26; j++) scanf("%lld", &v[i][j]);
        }
        for (int i = 0; str[i]; i++) add(str[i] - 'a');
        count();
        for (int i = 0; i < m; i++)
        {
            vector<pair<ll, ll> > ans;
            for (int j = 2; j < sz; j++)
                ans.pb(mp(val[j][i], cnt[j]));
            sort(ans.begin(), ans.end());
            for (auto t : ans)
            {
                if (k[i] > t.Y)
                    k[i] -= t.Y;
                else
                {
                    printf("%lld\n", t.X);
                    break;
                }
            }
        }
        puts("");
    }
} gao;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    Pow[0] = 1;
    for (int i = 1; i < N; i++) Pow[i] = Pow[i - 1] * 26 % mod;

    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        gao.init(m);
        gao.work();
    }
    return 0;
}
