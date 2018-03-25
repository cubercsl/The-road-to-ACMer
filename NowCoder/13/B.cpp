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

const int maxn = 45;
int n;
int a[maxn];
int b[maxn];
int v[maxn];

bool dfs(int pa, int pb, int dep)
{
    if (pa > n / 2 || pb > n / 2) return false;
    if (dep == n) return true;
    if (pa >= pb && (a[pa] = v[dep], dfs(pa + 1, pb, dep + 1)))
        return true;
    if (pa <= pb && (b[pb] = v[dep], dfs(pa, pb + 1, dep + 1)))
        return true;
    if (pa < pb && v[dep] == b[pa] && (a[pa] = v[dep], dfs(pa + 1, pb, dep + 1)))
        return true;
    if (pa > pb && v[dep] == a[pb] && (b[pb] = v[dep], dfs(pa, pb + 1, dep + 1)))
        return true;
    return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
int T;
cin >> T;
while (T--)
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    if (dfs(0, 0, 0))
        cout << "Frederica Bernkastel" << endl;
    else
        cout << "Furude Rika" << endl;
    return 0;
}
