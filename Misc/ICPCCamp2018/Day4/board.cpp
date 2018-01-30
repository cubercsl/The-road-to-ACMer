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

int x[100][100];

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
        int n, d;
        scanf("%d%d", &n, &d);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < d; j++)
                scanf("%d", &x[i][j]), --x[i][j];
        bool flag = 0;
        for (int i = 0; i < d; i++)
        {
            int tmp = 0;
            for (int j = 0; j < n; j++) tmp ^= x[j][i];
            flag |= true;
        }
        puts(flag ? "Alice" : "Bob");
    }
    return 0;
}