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

// 返回y中x的个数
const int N = 1 << 18;
int Next[N];
void initkmp(int x[], int m)
{
    int i = 0, j = Next[0] = -1;
    while (i < m)
    {
        while (j != -1 && x[i] != x[j]) j = Next[j];
        Next[++i] = ++j;
    }
}
int kmp(int x[], int m, int y[], int n)
{
    int i, j, ans;
    i = j = ans = 0;
    initkmp(x, m);
    while (i < n)
    {
        while (j != -1 && y[i] != x[j]) j = Next[j];
        i++, j++;
        if (j >= m) ans++, j = Next[j];
    }
    return ans;
}

int a[N], b[N];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        for (int i = 0; i < m; i++) scanf("%d", &b[i]);
        for (int i = 0; i < n; i++) a[i] %= k;
        for (int i = 0; i < m; i++) b[i] = (k - b[i] % k) % k;
        for (int i = 0; i < n - 1; i++) a[i] = (a[i + 1] - a[i] + k) % k;
        for (int i = 0; i < m - 1; i++) b[i] = (b[i + 1] - b[i] + k) % k;
        printf("%d\n", m - 1 ? kmp(b, m - 1, a, n - 1) : n);
    }
    return 0;
}
