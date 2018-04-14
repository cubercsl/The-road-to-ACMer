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

typedef unsigned long long ull;

const int N = 2005, M = 205;
const int base = mod;
char a[N][M], b[M][N];
ull p[N];
ull ha[N][M], hb[M][N];

int n, m;

inline ull get_hash(ull* h, int l, int r) { return h[r] - h[l - 1] * p[r - l + 1]; }

bool check(int x, int y)
{
    for (int i = 0; i < m; i++)
        if (get_hash(ha[x + i], 1, m) != get_hash(hb[i + 1], y, y + m - 1)) return false;
    return true;
}

ull unit_test()
{
    char c[N];
    cin >> c + 1;
    ull h = 0;
    for (int i = 1; c[i]; i++) (h *= base) += c[i];
    cout << h << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    p[0] = 1;
    for (int i = 1; i < N; i++) p[i] = p[i - 1] * base;
    // unit_test();
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i] + 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) ha[i][j] = ha[i][j - 1] * base + a[i][j];
    for (int i = 1; i <= m; i++) cin >> b[i] + 1;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) hb[i][j] = hb[i][j - 1] * base + b[i][j];
    for (int i = 1; i + m - 1 <= n; i++)
        for (int j = 1; j + m - 1 <= n; j++)
            if (check(i, j)) return cout << i << " " << j << endl, 0;
    return 0;
}