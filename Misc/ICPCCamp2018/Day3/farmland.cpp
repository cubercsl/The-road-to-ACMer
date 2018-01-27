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
const int mod = 998244353;
const double eps = 1e-6;

typedef vector<ll> vec;
typedef vector<vec> mat;
typedef vector<mat> Mat;

Mat mul(Mat& A, Mat& B)
{
    Mat C(A.size(), mat(A[0].size(), vec(A[0].size())));
    int n = A.size();
    int m = A[0].size();
    for (int u = 0; u < n; u++)
        for (int i = 0; i < m; i++)
            for (int k = 0; k < m; k++)
                if (A[u][i][k])
                    for (int j = 0; j < m; j++)
                        (C[u][i][j] += A[u][i][k] * B[u][k][j]) %= mod;
    return C;
}

Mat Pow(Mat& A, ll n)
{
    Mat B(A.size(), mat(A[0].size(), vec(A[0].size())));
    B = A;
    int sz = A[0].size();
    --n;
    for (; n; n >>= 1, A = mul(A, A))
        if (n & 1) B = mul(B, A);
    return B;
}

mat Add(mat& A, mat& B)
{
    int n = A.size();
    mat C(n, vec(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = (A[i][j] + B[i][j]) % mod;
    return C;
}

mat Sub(mat& A, mat& B)
{
    int n = A.size();
    mat C(n, vec(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = (A[i][j] - B[i][j] + mod) % mod;
    return C;
}

void fwt(Mat& a, int l, int r)
{
    if (l == r) return;
    int mid = l + r >> 1, len = mid - l + 1;
    fwt(a, l, mid);
    fwt(a, mid + 1, r);
    for (int i = l; i <= mid; i++)
    {
        mat u = a[i], v = a[i + len];
        a[i + len] = Add(u, v);
    }
}

void ifwt(Mat& a, int l, int r)
{
    if (l == r) return;
    int mid = l + r >> 1, len = mid - l + 1;
    for (int i = l; i <= mid; i++)
    {
        mat u = a[i], v = a[i + len];
        a[i + len] = Sub(v, u);
    }
    ifwt(a, l, mid);
    ifwt(a, mid + 1, r);
}

ll Pow(ll a, ll n)
{
    ll t = 1;
    for (; n; n >>= 1, (a *= a) %= mod)
        if (n & 1) (t *= a) %= mod;
    return t;
}

const int maxn = 50;
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
    void insert(const char* s, const int& id)
    {
        int u = 0, n = strlen(s);
        for (int i = 0; i < n; i++)
        {
            int c = idx(s[i]);
            if (ch[u][c] == -1) ch[u][c] = newnode();
            u = ch[u][c];
        }
        val[u] |= (1 << id);
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
            val[u] |= val[f[u]];
            for (int c = 0; c < 26; c++)
            {
                if (~ch[u][c])
                    f[ch[u][c]] = ch[f[u]][c], q.push(ch[u][c]);
                else
                    ch[u][c] = ch[f[u]][c];
            }
        }
    }
    void solve(int l, int n)
    {
        if (l == 0)
        {
            puts("0");
            return;
        }
        Mat G((1 << n), mat(sz, vec(sz)));
        for (int u = 0; u < sz; u++)
            for (int c = 0; c < 26; c++)
                G[val[ch[u][c]]][u][ch[u][c]]++;
        fwt(G, 0, G.size() - 1);
        G = Pow(G, l);
        ifwt(G, 0, G.size() - 1);
        ll ans = 0;
        for (int i = 0; i < sz; i++)
            (ans += G[(1 << n) - 1][rt][i]) %= mod;
        printf("%lld\n", ans);
    }
} ac;

char buf[10];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int l, n;
    scanf("%d%d", &l, &n);
    ac.init();
    for (int i = 0; i < n; i++)
    {
        scanf("%s", buf);
        ac.insert(buf, i);
    }
    ac.build();
    ac.solve(l, n);
    return 0;
}