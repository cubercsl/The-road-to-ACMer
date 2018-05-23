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

const int N = 105;
bool G[N][N];
int fa[N];
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
void unite(int x, int y)
{
    x = find(x), y = find(y);
    if (x != y) fa[x] = y;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    if (n < 3 || n != m) return cout << "Break up" << endl, 0;
    iota(fa, fa + N, 0);
    while (m--)
    {
        static int u, v;
        cin >> u >> v;
        if (G[u][v] || G[v][u] || u == v) return cout << "Break up" << endl, 0;
        G[u][v] = G[v][u] = true;
        unite(u, v);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (find(i) == i) cnt++;
    if (cnt == 1)
        cout << "Bingo" << endl;
    else
        cout << "Break up" << endl;
    return 0;
}
