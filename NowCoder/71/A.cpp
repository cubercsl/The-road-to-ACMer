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

const int maxn = 1000005;
int a[maxn];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, num;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        a[num]++;
    }
    int ans = 0;
    for(int i = 1; i < maxn; i++)
    {
        if(a[i])
        for(int j = i + i; j < maxn; j+=i)
            if(a[j])
            {
                ans += a[i];
                break;
            }
    }
    printf("%d\n", ans);
    return 0;
}
