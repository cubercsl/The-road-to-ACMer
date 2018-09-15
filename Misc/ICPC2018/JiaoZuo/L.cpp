#include <bits/stdc++.h>
using namespace std;

const int maxn = 50;
const int mod = 1e9 + 7;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
mat mul(mat& A, mat& B)
{
    mat C(A.size(), vec(B[0].size()));
    for (int i = 0; i < A.size(); i++)
        for (int k = 0; k < B.size(); k++)
            if (A[i][k]) // 对稀疏矩阵的优化
                for (int j = 0; j < B[0].size(); j++)
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
    return C;
}
mat Pow(mat A, ll n)
{
    mat B(A.size(), vec(A.size()));
    for (int i = 0; i < A.size(); i++) B[i][i] = 1;
    for (; n; n >>= 1, A = mul(A, A))
        if (n & 1) B = mul(B, A);
    return B;
}

struct Trie
{
    int ch[maxn][3], f[maxn], val[maxn];
    int sz, rt;
    int newnode()
    {
        memset(ch[sz], -1, sizeof(ch[sz])), val[sz] = 0;
        return sz++;
    }
    void init() { sz = 0, rt = newnode(); }
    inline int idx(char c) { return c - 'A'; };
    void insert(const char* s)
    {
        int u = 0, n = strlen(s);
        for (int i = 0; i < n; i++)
        {
            int c = idx(s[i]);
            if (ch[u][c] == -1) ch[u][c] = newnode();
            u = ch[u][c];
        }
        val[u] = 1;
    }
    mat tr;
    void build()
    {
        queue<int> q;
        f[rt] = rt;
        for (int c = 0; c < 3; c++)
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
            for (int c = 0; c < 3; c++)
            {
                if (~ch[u][c])
                    f[ch[u][c]] = ch[f[u]][c], q.push(ch[u][c]);
                else
                    ch[u][c] = ch[f[u]][c];
            }
        }
        mat A(sz, vec(sz));
        for (int u = 0; u < sz; u++)
        {
            for (int c = 0; c < 3; c++)
                if (!val[ch[u][c]])
                    A[u][ch[u][c]]++;
        }
        tr = A;
    }
    ll solve(ll n)
    {
        mat A = Pow(tr, n);
        ll ans = 0;
        for (int i = 0; i < sz; i++) (ans += A[0][i]) %= mod;
        return ans;
    }
} ac;

int main()
{
    ac.init();
    ac.insert("AAA");
    ac.insert("BBB");
    ac.insert("CCC");
    ac.insert("ACB");
    ac.insert("BCA");
    ac.insert("CAC");
    ac.insert("CBC");
    ac.build();
    int T;
    scanf("%d", &T);
    while (T--)
    {
        ll n;
        scanf("%lld", &n);
        printf("%lld\n", ac.solve(n));
    }
}