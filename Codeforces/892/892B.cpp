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

const int N = 1e6 + 5;
int bit[N];
int n;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    while (~scanf("%d", &n))
    {
        clr(bit, 0);
        for (int i = 1; i <= n; i++)
        {
            int len;
            scanf("%d", &len);
            int l = max(1, i - len);
            bit[l]++;
            bit[i]--;
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++)
            bit[i] = bit[i - 1] + bit[i], cnt += bit[i] == 0;
        printf("%d\n", cnt);
    }
    return 0;
}