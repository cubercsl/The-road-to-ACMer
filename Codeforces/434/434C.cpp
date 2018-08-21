#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 8;
const int mod = 1e9 + 7;
struct Trie
{
    int ch[N][20], f[N], val[N];
    int sz, rt;
    int newnode()
    {
        memset(ch[sz], -1, sizeof(ch[sz])), val[sz] = 0;
        return sz++;
    }
    void insert(const vector<int>& s, int v)
    {
        int u = rt;
        for (auto& c : s)
        {
            if (!~ch[u][c]) ch[u][c] = newnode();
            u = ch[u][c];
        }
        val[u] += v;
    }
    void build()
    {
        queue<int> q;
        f[rt] = rt;
        for (int c = 0; c < m; c++)
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
            for (int c = 0; c < m; c++)
            {
                if (~ch[u][c])
                    f[ch[u][c]] = ch[f[u]][c], q.push(ch[u][c]);
                else
                    ch[u][c] = ch[f[u]][c];
            }
        }
    }
    vector<int> l, r;
    int m, k;
    int dp[N][N][N << 1];
    void init(int m, int k)
    {
        sz = 0, rt = newnode();
        this->m = m, this->k = k;
        memset(dp, -1, sizeof(dp));
        set(l), set(r);
        assert(l.size() <= r.size());
        l.resize(r.size());
    }
    void set(vector<int>& num)
    {
        int n;
        scanf("%d", &n);
        num.resize(n);
        for (auto& t : num) scanf("%d", &t);
        reverse(num.begin(), num.end());
    }
    int solve()
    {
        return dfs(r.size() - 1, rt);
    }
    int dfs(int pos, int state, int sum = 0, bool lead = true, bool limit_l = true, bool limit_r = true)
    {
        if (sum > k) return 0;
        if (!~pos) return 1;
        if (!limit_l && !limit_r && !lead && ~dp[pos][state][sum]) return dp[pos][state][sum];
        int ans = 0;
        for (int c = 0; c < m; c++)
        {
            if (limit_l && c < l[pos]) continue;
            if (limit_r && c > r[pos]) continue;
            int new_state = state;
            if (!lead || c) new_state = ch[state][c];
            ans += dfs(pos - 1, new_state, sum + val[new_state], lead && c == 0, limit_l && c == l[pos], limit_r && c == r[pos]);
            if (ans >= mod) ans -= mod;
        }
        if (!limit_l && !limit_r && !lead) dp[pos][state][sum] = ans;
        return ans;
    }
} solver;

int main()
{

    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    solver.init(m, k);
    for (int i = 0, len, val; i < n; i++)
    {
        scanf("%d", &len);
        vector<int> num(len);
        for (auto& t : num) scanf("%d", &t);
        scanf("%d", &val);
        solver.insert(num, val);
    }
    solver.build();
    printf("%d\n", solver.solve());
}