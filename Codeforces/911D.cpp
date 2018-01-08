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

const int maxn = 1 << 18;

int a[maxn];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m;
    while (~scanf("%d", &n))
    {
        for (int i = 0; i < n; i++) scanf("%d", a + i);
        int cnt = 0;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (a[i] > a[j]) cnt++;
        cnt &= 1;
        int l, r;
        scanf("%d", &m);
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d", &l, &r);
            const int len = (r - l + 1);
            int pn = (len * (len - 1)) / 2;
            if (pn & 1)
                cnt ^= 1;
            if (cnt)
                printf("odd\n");
            else
                printf("even\n");
        }
    }
    return 0;
}
