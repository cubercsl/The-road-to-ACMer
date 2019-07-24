#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define debug(...) fprintf(stderr, ##__VA_ARGS__)
#else
#define debug(...)
#endif

typedef tuple<int, int, int> milk;
const long long INF = 1e18;

vector<long long> solve(const vector<pair<int, int>>& a, int dest = -1)
{
    vector<long long> c(a.size(), INF), t(a.size(), INF);
    c[0] = ~dest ? abs(dest - a[0].first) : 0;
    t[0] = 0;
    for (int i = 1; i < a.size(); i++)
    {
        int d = abs(a[i].first - a[i - 1].first);
        for (int j = 0; j < i; j++) t[j] += d;
        for (int j = i; j; j--) t[j] = min(t[j], t[j - 1] + a[i].second);
        for (int j = 0; j <= i; j++) c[j] = min(c[j], t[j] + (~dest ? abs(dest - a[i].first) : 0));
    }
    return c;
}

vector<long long> merge(const vector<long long>& a, const vector<long long>& b)
{
    vector<long long> c(a.size() + b.size() - 1, INF);
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < b.size(); j++)
            c[i + j] = min(c[i + j], a[i] + b[j]);
    return c;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T, kase = 0;
    scanf("%d", &T);
    while (T--)
    {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        vector<int> x{1};
        vector<milk> p;

        for (int i = 0, r, c, t; i < k; i++)
        {
            scanf("%d%d%d", &r, &c, &t);
            x.push_back(r);
            p.emplace_back(r, c, t);
        }

        sort(x.begin(), x.end());
        x.erase(unique(x.begin(), x.end()), x.end());

        vector<vector<pair<int, int>>> a(x.size());
        vector<long long> ans(k + 1, INF);

        for (int i = 0; i < k; i++) a[lower_bound(x.begin(), x.end(), get<0>(p[i])) - x.begin()]
                                        .emplace_back(get<1>(p[i]), get<2>(p[i]));
        for (auto& t : a) sort(t.begin(), t.end());

        static vector<long long> f[2];

        auto& t = a[0];
        t.insert(t.begin(), {1, 0});
        f[0] = solve(t, m + 1 >> 1);
        auto g = solve(t);
        for (int i = 0; i < g.size(); i++) ans[i] = min(ans[i], g[i]);
        for (int i = 1; i < x.size(); i++)
        {
            auto p = lower_bound(a[i].begin(), a[i].end(), make_pair(m + 1 >> 1, 0));
            vector<pair<int, int>> t0(a[i].begin(), p), t1(p, a[i].end());
            t0.push_back({m + 1 >> 1, 0});
            reverse(t0.begin(), t0.end());
            t1.insert(t1.begin(), {m + 1 >> 1, 0});
            auto f0 = solve(t0, m + 1 >> 1);
            auto f1 = solve(t1, m + 1 >> 1);
            auto g0 = solve(t0);
            auto g1 = solve(t1);
            g0 = merge(f1, g0);
            g1 = merge(f0, g1);

            assert(g0.size() == g1.size());
            vector<long long> g(g0.size());

            for (int j = 0; j < g.size(); j++) g[j] = min(g0[j], g1[j]);
            g = merge(f[i & 1 ^ 1], g);
            f[i & 1] = merge(f[i & 1 ^ 1], merge(f0, f1));

            for (int j = 0; j < g.size(); j++)
            {
                f[i & 1][j] += x[i] - x[i - 1];
                g[j] += x[i] - x[i - 1];
                ans[j] = min(ans[j], g[j]);
            }
        }
        for (int i = 1; i <= k; i++) printf("%lld%c", ans[i], " \n"[i == k]);
    }
}