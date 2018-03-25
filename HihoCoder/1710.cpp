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
int a[N];
int L[N], R[N], len[N];
int tot;
inline void merge(const int& n)
{
    tot = 0;
    for (int i = 1; i < n;)
    {
        int cur = a[i];
        L[++tot] = i++;
        while (a[i] == cur) i++;
        R[tot] = i;
    }
    // for (int i = 1; i <= tot; i++) cout << L[i] << " " << R[i] << endl;
    for (int i = 1; i <= tot; i++) len[i] = R[i] - L[i] + 1;
}

int mmax[N][30];
void init(const int& n)
{
    for (int i = 1; i <= n; i++) mmax[i][0] = len[i];
    for (int j = 1; (1 << j) <= n; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
        {
            mmax[i][j] = max(mmax[i][j - 1], mmax[i + (1 << (j - 1))][j - 1]);
        }
}
int rmq(int l, int r)
{
    int k = 31 - __builtin_clz(r - l + 1);
    return max(mmax[l][k], mmax[r - (1 << k) + 1][k]);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    for (int i = n - 1; i; i--) a[i] = a[i] - a[i - 1];
    merge(n);
    init(tot);
    while (m--)
    {
        static int l, r;
        scanf("%d%d", &l, &r);
        int ll = lower_bound(L + 1, L + tot + 1, l) - L;
        int rr = upper_bound(R + 1, R + tot + 1, r) - R - 1;
        if (rr + 1 == ll)
        {
            printf("%d\n", max(L[ll] - l + 1, r - R[rr] + 1));
            continue;
        }
        if (rr < ll)
        {
            printf("%d\n", r - l + 1);
            continue;
        }
        int ans = rmq(ll, rr);
        ans = max(ans, max(L[ll] - l + 1, r - R[rr] + 1));
        printf("%d\n", ans);
    }
    return 0;
}