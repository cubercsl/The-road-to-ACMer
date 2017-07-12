#include <bits/stdc++.h>
using namespace std;
#define clr(a,x) memset(a, x, sizeof(a))
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;

const int maxn = 1e5 + 5;
int M;
PII equ[maxn];

int greedy(int n, int m)
{
    int i, sum = 0;
    for (i = 0; sum + equ[i].X <= m && i < n; i++)
        sum += equ[i].X;
    return i;
}

bool ok(int x, int n, int m)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (m >= equ[i].X)
        {
            if (equ[i].Y >= x)
                cnt++, m -= equ[i].X;
        }
        else break;
    return cnt == M;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++)
            scanf("%d%d", &equ[i].Y, &equ[i].X);
        sort(equ, equ + n);
        M = greedy(n, m);
        int L = -1, R = 10001, ans;
        while (L <= R)
        {
            int mid = (L + R) >> 1;
            if (ok(mid, n, m))
                L = mid + 1, ans = mid;
            else
                R = mid - 1;
        }
        printf("%d %d\n", M, ans);
    }
    return 0;
}
