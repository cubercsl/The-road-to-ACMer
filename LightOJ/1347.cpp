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
const int N = 5005;
ull h[3][N], Pow[N];
char s[N];
int len[3];
inline ull gethash(ull* h, int l, int r) { return h[r] - h[l] * Pow[r - l]; }

bool ok(int m)
{
    vector<ull> v[2];
    for (int i = 0; i < 2; i++)
    {
        int n = len[i];
        for (int j = 0; j + m - 1 < n; j++) v[i].pb(gethash(h[i], j, j + m));
        sort(v[i].begin(), v[i].end());
    }
    int n = len[2];
    for (int i = 0; i + m - 1 < n; i++)
    {
        ull tmp = gethash(h[2], i, i + m);
        if (binary_search(v[0].begin(), v[0].end(), tmp) && binary_search(v[1].begin(), v[1].end(), tmp)) return true;
    }
    return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    Pow[0] = 1;
    for (int i = 1; i < N; i++) Pow[i] = Pow[i - 1] * mod;
    int T, kase = 0;
    scanf("%d", &T);
    while (T--)
    {
        int lb = 1, ub = INF, ans = 0;
        for (int i = 0; i < 3; i++)
        {
            scanf("%s", s);
            int n = len[i] = strlen(s);
            ub = min(ub, n);
            for (int j = 0; j < n; j++) h[i][j + 1] = h[i][j] * mod + s[j];
        }
        while (lb <= ub)
        {
            int mid = lb + ub >> 1;
            if (ok(mid))
                ans = mid, lb = mid + 1;
            else
                ub = mid - 1;
        }
        printf("Case %d: %d\n", ++kase, ans);
    }
    return 0;
}
