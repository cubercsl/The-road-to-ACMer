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

const int N = 1 << 19;
struct Node
{
    int pre, nxt, val;
} a[N];
int top[N], bot[N];

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
        int n, q;
        int tot = 0;
        scanf("%d%d", &n, &q);
        clr(top, 0);
        while (q--)
        {
            static int op, s, t;
            scanf("%d", &op);
            if (op == 1)
            {
                scanf("%d%d", &s, &t);
                a[++tot] = {top[s], 0, t};
                if (!top[s])
                    bot[s] = tot;
                else
                    a[top[s]].nxt = tot;
                top[s] = tot;
            }
            else if (op == 2)
            {
                scanf("%d", &s);
                if (!top[s])
                    puts("EMPTY");
                else
                {
                    printf("%d\n", a[top[s]].val);
                    top[s] = a[top[s]].pre;
                }
            }
            else
            {
                scanf("%d%d", &s, &t);
                if (!top[t])
                    continue;
                else if (!top[s])
                {
                    top[s] = top[t];
                    bot[s] = bot[t];
                }
                else
                {
                    a[top[s]].nxt = bot[t];
                    a[bot[t]].pre = top[s];
                }
                bot[t] = 0;
                top[s] = top[t];
                top[t] = 0;
            }
        }
    }
    return 0;
}
