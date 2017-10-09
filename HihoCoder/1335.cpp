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

const int maxn = 1 << 17;
map<string, int> M;
vector<string> name;
vector<int> email[maxn];
vector<int> ans[maxn];

/*union-find-set*/
int par[maxn];
inline void init(int n)
{
    for (int i = 0; i < n; i++) par[i] = i;
}
int find(int x) { return par[x] == x ? x : par[x] = find(par[x]); }
inline bool same(int x, int y) { return find(x) == find(y); }
inline void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y) return;
    par[y] = x;
}
/****************/

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m;
    cin >> n;
    string buf;
    int sz = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> buf;
        name.pb(buf);
        cin >> m;
        while (m--)
        {
            cin >> buf;
            if (M.find(buf) == M.end()) M[buf] = sz++;
            int id = M[buf];
            email[id].pb(i);
        }
    }

    // 0~n-1 username
    // n+1 email
    init(n + sz);
    for (int i = 0; i < sz; i++)
        for (auto& user : email[i])
            unite(user, n + i);
    for (int i = 0; i < n; i++)
        ans[find(i)].pb(i);
    vector<int> tmp;
    for (int i = 0; i < n; i++)
    {
        if (!ans[i].size()) continue;
        sort(ans[i].begin(), ans[i].end());
        tmp.pb(i);
    }
    sort(tmp.begin(), tmp.end(), [](int a, int b) { return ans[a][0] < ans[b][0]; });
    for (auto& id : tmp)
    {
        for (int i = 0; i < ans[id].size(); i++)
        {
            if (i) cout << " ";
            cout << name[ans[id][i]];
        }
        cout << endl;
    }
    return 0;
}
