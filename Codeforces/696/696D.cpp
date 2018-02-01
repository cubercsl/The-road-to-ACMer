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

const int maxn = 20005;

typedef vector<ll> vec;
typedef vector<vec> mat;

mat mul(mat& A, mat& B)
{
    mat C(A.size(), vec(B[0].size()));
    for (int i = 0; i < A.size(); i++)
        for (int j = 0; j < B.size(); j++)
        {
            C[i][j] = -1e18;
            for (int k = 0; k < B[0].size(); k++)
                C[i][j] = max(C[i][j], A[i][k] + B[k][j]);
        }
    return C;
}

mat Pow(mat A, ll n)
{
    mat B(A.size(), vec(A.size()));
    B = A;
    n--;
    for (; n; n >>= 1, A = mul(A, A))
        if (n & 1) B = mul(B, A);
    return B;
}

struct Trie
{
    int ch[maxn][26], f[maxn], val[maxn];
    int sz, rt;
    int newnode()
    {
        clr(ch[sz], -1), val[sz] = 0;
        return sz++;
    }
    void init() { sz = 0, rt = newnode(); }
    inline int idx(char c) { return c - 'a'; };
    void insert(const char* s, const int& v)
    {
        int u = 0, n = strlen(s);
        for (int i = 0; i < n; i++)
        {
            int c = idx(s[i]);
            if (ch[u][c] == -1) ch[u][c] = newnode();
            u = ch[u][c];
        }
        val[u] += v;
    }
    void build()
    {
        queue<int> q;
        f[rt] = rt;
        for (int c = 0; c < 26; c++)
        {
            if (~ch[rt][c])
                f[ch[rt][c]] = rt, q.push(ch[rt][c]);
            else
                ch[rt][c] = rt;
        }
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            val[u] += val[f[u]];
            for (int c = 0; c < 26; c++)
            {
                if (~ch[u][c])
                    f[ch[u][c]] = ch[f[u]][c], q.push(ch[u][c]);
                else
                    ch[u][c] = ch[f[u]][c];
            }
        }
    }
    ll solve(ll m)
    {
        mat G(sz, vec(sz));
        for (int i = 0; i < sz; i++)
            for (int j = 0; j < sz; j++)
                G[i][j] = -1e18;
        for (int u = 0; u < sz; u++)
            for (int c = 0; c < 26; c++)
                G[u][ch[u][c]] = val[ch[u][c]];
        G = Pow(G, m);
        ll ret = 0;
        for (int i = 0; i < sz; i++)
            ret = max(G[0][i], ret);
        return ret;
    }
};

Trie ac;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    ll m;
    int v[205];
    char buf[205];
    while (~scanf("%d%lld", &n, &m))
    {
        ac.init();
        for (int i = 0; i < n; i++)
            scanf("%d", &v[i]);
        for (int i = 0; i < n; i++)
        {
            scanf("%s", buf);
            ac.insert(buf, v[i]);
        }
        ac.build();
        printf("%lld\n", ac.solve(m));
    }
    return 0;
}
