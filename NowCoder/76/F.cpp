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

const int N = 55;
bool G[N][N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m;
    while(~scanf("%d%d", &n, &m))
    {
        clr(G, 0);
        while(m--)
        {
            static int u, v;
            scanf("%d%d", &u, &v);
            --u, --v;
            G[u][v] = 1;
        }
        for(int k = 0; k < n; k++)
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    G[i][j] |= (G[i][k] & G[k][j]);
        puts(G[0][n - 1] ? "Yes" :"No");
        
    }
    return 0;
}