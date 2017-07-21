// Rochambeau, POJ2962

/*Sample Input
3 3
0<1
1<2
2<0
3 5
0<1
0>1
1<2
1>2
0<2
4 4
0<1
0>1
2<3
2>3
1 0
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
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

const int maxn = 2005;
int par[maxn];

void init(int n)
{
    for (int i = 0; i < n; i++)
        par[i] = i;
}

int find(int x)
{
    if (par[x] != x)
        par[x] = find(par[x]);
    return par[x];
}

void unite (int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y) return;
    par[y] = x;
}

bool same(int x, int y)
{
    return find(x) == find(y);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {
        int x[maxn], y[maxn];
        bool draw[maxn];
        clr(draw, 0);
        for (int i = 0; i < m; i++)
        {
            int a, b;
            char c;
            scanf("%d%c%d", &a, &c, &b);
            if (c == '<')
                x[i] = b, y[i] = a;
            else if (c == '>')
                x[i] = a, y[i] = b;
            else
                x[i] = a, y[i] = b, draw[i] = true;
        }
        int cnt = 0; // 枚举每个人作为裁判，统计没有出现矛盾的次数。
        int ans = 0; // 记录出现矛盾的时间，即可以确定裁判的时间。
        int player;
        for (int i = 0; i < n; i++)
        {
            init(3 * n);
            bool flag = true;
            for (int j = 0; j < m; j++)
            {
                if (x[j] == i || y[j] == i)
                    continue; // 裁判可以任意出，所以直接跳过。
                if (draw[j])
                {
                    if (same(x[j], y[j] + n) || same(x[j], y[j] + 2 * n))
                    {
                        ans = max(ans, j + 1); // 出现矛盾
                        flag = false;
                        break;
                    }
                    else
                    {
                        unite(x[j], y[j]);
                        unite(x[j] + n, y[j] + n);
                        unite(x[j] + 2 * n, y[j] + 2 * n);
                    }
                }
                else
                {
                    if (same(x[j], y[j]) || same(x[j], y[j] + 2 * n))
                    {
                        ans = max(ans, j + 1); // 出现矛盾
                        flag = false;
                        break;
                    }
                    else
                    {
                        unite(x[j], y[j] + n);
                        unite(x[j] + n, y[j] + 2 * n);
                        unite(x[j] + 2 * n, y[j]);
                    }
                }
            }
            if (flag)
                cnt++, player = i;
        }
        if (cnt == 0)
            printf("Impossible\n");
        else if (cnt == 1)
            printf("Player %d can be determined to be the judge after %d lines\n", player, ans);
        else
            printf("Can not determine\n");
    }
    return 0;
}
