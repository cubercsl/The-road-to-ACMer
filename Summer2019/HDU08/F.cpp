#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
const ull Seed_Pool[] = {146527, 19260817};
const ull Mod_Pool[] = {1000000009, 998244353};
struct Hash
{
    ull SEED, MOD;
    vector<ull> p, h;
    Hash() {}
    Hash(const string& s, const int& seed_index, const int& mod_index)
    {
        SEED = Seed_Pool[seed_index];
        MOD = Mod_Pool[mod_index];
        int n = s.length();
        p.resize(n + 1), h.resize(n + 1);
        p[0] = 1;
        for (int i = 1; i <= n; i++) p[i] = p[i - 1] * SEED % MOD;
        for (int i = 1; i <= n; i++) h[i] = (h[i - 1] * SEED % MOD + s[i - 1]) % MOD;
    }
    ull get(int l, int r) { return (h[r] - h[l] * p[r - l] % MOD + MOD) % MOD; }
    ull substr(int l, int m) { return get(l, l + m); }
};

const int N = 1 << 17;
char buf[N];
int len[N];
Hash h[N];
int n;
unordered_set<ull> pre, dic;
bool check(int m, int x, int y)
{
    pre.clear(), dic.clear();
    for (int i = 0; i < n; i++)
        pre.insert(h[i].substr(0, m));
    for (int i = 0; i + m - 1 < len[x]; i++)
        dic.insert(h[x].substr(i, m));
    for (int i = 0; i + m - 1 < len[y]; i++)
        if (dic.count(h[y].substr(i, m)) && pre.count(h[y].substr(i, m))) return true;
    return false;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%s", buf);
            len[i] = strlen(buf);
            h[i] = Hash(buf, 0, 0);
        }
        int q;
        scanf("%d", &q);
        while (q--)
        {
            static int x, y;
            scanf("%d%d", &x, &y);
            --x, --y;
            int l = 0, r = min(len[x], len[y]);
            int ans = 0;
            while (l <= r)
            {
                int m = l + r >> 1;
                if (check(m, x, y))
                    l = m + 1, ans = m;
                else
                    r = m - 1;
            }
            printf("%d\n", ans);
        }
    }
}