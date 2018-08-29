#include <bits/stdc++.h>
using namespace std;

inline string work(const vector<int>& a)
{
    string s;
    for (int i = 0; i < 4; i++)
        s += bitset<8>(a[i]).to_string();
    return s;
}

constexpr int N = 1 << 20;
struct Trie
{
    int ch[N][2], val[N];
    int rt, sz;
    int newnode()
    {
        memset(ch[sz], -1, sizeof(ch[sz]));
        val[sz] = 0;
        return sz++;
    }
    void init() { sz = 0, rt = newnode(); }
    void insert(const string& s, int a)
    {
        int u = rt;
        for (auto& t : s)
        {
            if (a == 0) break;
            a--;
            int c = t - '0';
            if (!~ch[u][c]) ch[u][c] = newnode();
            u = ch[u][c];
        }
        val[u] = 1;
    }
    vector<pair<string, int>> ans;
    void query()
    {
        ans.clear();
        memset(path, 0, sizeof(path));
        dfs(rt, 0);
        printf("%d\n", static_cast<int>(ans.size()));
        for (auto& t : ans) printf("%s/%d\n", t.first.c_str(), t.second);
    }
    int path[32];

    inline string gao(const int path[])
    {
        string s;
        for (int i = 0; i < 4; i++)
        {
            if (i) s.push_back('.');
            int t = 0;
            for (int j = 0; j < 8; j++)
                t = t << 1 | (path[i * 8 + j]);
            s += to_string(t);
        }
        return s;
    }

    void dfs(int u, int dep)
    {
        for (int c = 0; c < 2; c++)
        {
            path[dep] = c;
            if (!~ch[u][c])
            {
                ans.emplace_back(gao(path), dep + 1);
            }
            else if (!val[ch[u][c]])
                dfs(ch[u][c], dep + 1);
        }
        path[dep] = 0;
    }

} trie;

int main()
{
    int T, kase = 0;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        trie.init();
        for (int i = 0; i < n; i++)
        {
            vector<int> a(5);
            scanf("%d.%d.%d.%d/%d", &a[0], &a[1], &a[2], &a[3], &a[4]);
            string s = work(a);
            if (a[4] == 0)
            {
                n = -1;
                break;
            }
            trie.insert(s, a[4]);
        }
        printf("Case #%d:\n", ++kase);
        if (n == 0)
        {
            puts("1");
            puts("0.0.0.0/0");
            continue;
        }
        if (n == -1)
        {
            puts("0");
            continue;
        }
        trie.query();
    }
}