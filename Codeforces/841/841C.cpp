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

bool cmp (int a, int b)
{
    return a > b;
}
const int maxn = 2e5 + 5;
int a[maxn], b[maxn], d[maxn];
PII c[maxn];

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        for (int i = 0; i < n; i++)
            scanf("%d", a + i);
        sort(a, a + n, cmp);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", b + i);
            c[i] = mp(b[i], i);
        }
        sort(c, c + n);
        for (int i = 0; i < n; i++)
            d[c[i].Y] = a[i];
        for (int i = 0; i < n; i++)
        {
            if (i) putchar(' ');
            printf("%d", d[i]);
        }
        puts("");
    }
    return 0;
}
