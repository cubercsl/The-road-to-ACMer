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

const int N = 105;

struct Node
{
    int a, b, id;
};

Node cup[N];
inline bool solve(const int& n, int w)
{
    sort(cup, cup + n, [](Node a, Node b) {
        return a.a < b.a;
    });
    for (int i = 0; i < n; i++) cup[i].b = (cup[i].a + 1) / 2, w -= cup[i].b;
    if (w < 0) return false;
    // puts("!!!");
    for (int i = n - 1; w > 0 && ~i; i--)
    {
        Node& c = cup[i];
        if (c.a - c.b <= w)
            w -= c.a - c.b, c.b = c.a;
        else
            c.b += w, w = 0;
    }
    sort(cup, cup + n, [](Node a, Node b) {
        return a.id < b.id;
    });
    return w >= 0;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, w;
    while (~scanf("%d%d", &n, &w))
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &cup[i].a);
            cup[i].id = i;
        }
        if (solve(n, w))
        {
            for (int i = 0; i < n; i++)
                printf("%d ", cup[i].b);
        }
        else
            puts("-1");
    }
    return 0;
}
