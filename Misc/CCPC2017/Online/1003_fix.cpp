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

const int maxn = 10;

bool G[maxn][maxn];

bool solve(int n)
{
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            for (int k = j + 1; k < n; k++)
                if (G[i][j]&G[j][k]&G[k][i])
                    return false;
                else if (!G[i][j] & !G[j][k] & !G[k][i])
                    return false;
    return true;
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
        int n, s;
        scanf("%d", &n);
        if (n > 5)
        {
            for (int i = 0; i < n; i++)
                for (int j = i + 1; j < n; j++)
                    scanf("%d", &s);
            puts("Bad Team!");
            continue;
        }
        clr(G, 0);
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
            {
                scanf("%d", &s);
                G[i][j] = G[j][i] = s;
            }
        if (solve(n))
            puts("Great Team!");
        else
            puts("Bad Team!");
    }
    return 0;
}
