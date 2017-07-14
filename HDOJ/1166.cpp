// 敌兵布阵, HDU1166

/*Sample Input
1
10
1 2 3 4 5 6 7 8 9 10
Query 1 3
Add 3 6
Query 2 7
Sub 10 2
Add 6 3
Query 3 10
End 
*/

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
int BIT[maxn];
int n;
void add(int i, int x)
{
    while (i <= n)
    {
        BIT[i] += x;
        i += i & -i;
    }
}

int query(int i)
{
    int s = 0;
    while (i > 0)
    {
        s += BIT[i];
        i -= i & -i;
    }
    return s;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int t;
    scanf("%d", &t);
    int kase = 0;
    while (t--)
    {
        scanf("%d", &n);
        clr(BIT, 0);
        for (int i = 1; i <= n; i++)
        {
            int num;
            scanf("%d", &num);
            add(i, num);
        }
        printf("Case %d:\n", ++kase);
        while (1)
        {
            char cmd[10];
            int a, b;
            scanf("%s", cmd);
            if (cmd[0] == 'E')
                break;
            scanf("%d%d", &a, &b);
            if (cmd[0] == 'Q')
                printf("%d\n", query(b) - query(a - 1));
            else if (cmd[0] == 'A')
                add(a, b);
            else if (cmd[0] == 'S')
                add(a, -b);
        }
    }
    return 0;
}
