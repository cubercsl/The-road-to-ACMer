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

const int N = 1 << 17;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin int n;
    map<string, int> dic = {{"Constant", 0}, {"Variable", 1}};
    while (cin >> n)
    {
        vector<int> a(n), b(n);
        string sa, sb;
        int aa, bb;
        cin >> sa, aa = dic[sa];
        for (auto& t : a) cin >> t;
        cin >> sb, bb = dic[sb];
        for (auto& t : b) cin >> t;
        if (aa + bb == 0)
        {
            if (a == b)
                cout << 0 << endl;
            else
                cout << -1 << endl;
            continue;
        }
        vector<int> fa(N), cnt(N, 1);
        iota(fa.begin(), fa.end(), 0);
        function<int(int)> find = [&](int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); };
        auto unite = [&](int x, int y) {
            x = find(x), y = find(y);
            if (x == y) return;
            fa[x] = y;
            cnt[y] += cnt[x];
        };
        int ans = 0;
        if (aa + bb == 1)
        {
            if (!aa) swap(a, b);
            vector<vector<int> > G(N), GG(N);
            vector<int> deg(N);
            auto check = [&](const vector<int>& g) {
                int n = g.size();
                queue<int> q;
                for (auto& u : g)
                    if (!deg[u]) q.push(u);
                while (!q.empty())
                {
                    int u = q.front();
                    q.pop();
                    --n;
                    for (auto& v : G[u])
                        if (--deg[v] == 0) q.push(v);
                }
                return n == 0;
            };
            for (int i = 0; i < n; i++) G[a[i]].push_back(b[i]), unite(a[i], b[i]), ++deg[b[i]];
            for (int i = 0; i < N; i++) GG[find(i)].push_back(i);
            for (auto& g : GG)
            {
                if(g.empty()) continue;
                if (check(g))
                    ans += g.size() - 1;
                else
                    ans += g.size();
            }
            cout << ans << endl;
        }
        else
        {
            for (int i = 0; i < n; i++) unite(a[i], b[i]);
            for (int i = 0; i < N; i++)
                if (find(i) == i) ans += (cnt[i] - 1);
            cout << ans << endl;
        }
    }
    return 0;
}