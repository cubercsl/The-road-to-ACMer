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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    while(~scanf("%d", &n))
    {
        int num;
        int a[3] = {0};
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &num);
            a[num]++;
        }
        int cnt = min(a[1], a[2]);
        a[1] -= cnt, a[2] -= cnt;
        cnt += a[1] / 3;
        printf("%d\n", cnt);
    }
    return 0;
}
