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

const int MAX = 1 << 18;
int n, a, b, p[MAX], fa[MAX];
map<int, int> M;

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
    scanf("%d%d%d", &n, &a, &b);
    int Max = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
        M[p[i]] = i;
        Max = max(Max, p[i]);
    }
    if (Max >= max(a, b))
        return puts("NO"), 0;
    for (int i = 0; i <= n + 1; i++) fa[i] = i;
    for (int i = 1; i <= n; i++)
    {
        if (M[a - p[i]])
            unite(i, M[a - p[i]]);
        else
            unite(i, n + 1);
        if (M[b - p[i]])
            unite(i, M[b - p[i]]);
        else
            unite(i, 0);
    }
    int A = find(0);
    int B = find(n + 1);
    if (A != B)
    {
        puts("YES");
        for (int i = 1; i <= n; i++) printf("%d%c", find(i) != A, " \n"[i == n]);
    }
    else
        puts("NO");
    return 0;
}