#include <bits/stdc++.h>
using namespace std;

vector<string> vec;

const int N = 500005;
int ans[N];
struct Trie
{
    int ch[N][27];
    int f[N];
    vector<int> q[N];
    int sz, rt;
    int len[N];
    int newnode()
    {
        len[sz] = 0;
        q[sz].clear();
        memset(ch[sz], -1, sizeof(ch[sz]));
        return sz++;
    }
    void init()
    {
        for (int i = 0; i < sz; i++) q[i].clear();
        sz = 0;
        rt = newnode();
    }
    inline int idx(char x) { return isalpha(x) ? x - 'a' : 26; }
    void insert(const string& s, int id)
    {
        int u = rt;
        int l = 0;
        for (auto& t : s)
        {
            int c = idx(t);
            if (!~ch[u][c]) ch[u][c] = newnode();
            u = ch[u][c];
            len[u] = ++l;
        }
        q[u].push_back(id);
    }
    void build()
    {
        queue<int> q;
        f[rt] = rt;
        for (int c = 0; c < 27; c++)
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
            for (int c = 0; c < 27; c++)
            {
                if (~ch[u][c])
                    f[ch[u][c]] = ch[f[u]][c], q.push(ch[u][c]);
                else
                    ch[u][c] = ch[f[u]][c];
            }
        }
    }
    void solve(const string& s)
    {
        int n = s.length() / 2 + 1;
        int u = rt;
        for (auto& t : s)
        {
            int c = idx(t);
            u = ch[u][c];
            int tmp = u;
            while (tmp != rt)
            {
                if (len[tmp] <= n)
                for (auto& qid : q[tmp]) ans[qid]++;
                tmp = f[tmp];
            }
        }
    }
} ac;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int n, q;
        cin >> n >> q;
        vec.clear();
        string s;
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            s = s + "#" + s;
            vec.push_back(s);
        }
        ac.init();
        string pre, suf;
        for (int i = 0; i < q; i++)
        {
            cin >> pre >> suf;
            s = suf + "#" + pre;
            ac.insert(s, i);
        }
        ac.build();
        for (int i = 0; i < q; i++) ans[i] = 0;
        for (int i = 0; i < n; i++) ac.solve(vec[i]);
        for (int i = 0; i < q; i++) cout << ans[i] << '\n';
    }
}