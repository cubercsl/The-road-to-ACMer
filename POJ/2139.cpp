#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
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

const int maxn = 310;
const int maxm = 1e5 + 7;;
int n, m;
int c[maxn][maxn];

void floyd()
{
    cout << "floyd" << endl;
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
}

int main()
{
#ifdef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin
    clr(c, 0x3f);
    for (int i = 0; i < n; i++)
        c[i][i] = 0;
    cin >> n >> m;
    while (m--)
    {
        int t;
        cin >> t;
        int G[maxn];
        for (int i = 0; i < t; i++)
            cin >> G[i];
        for (int i = 0; i < t; i++)
            for (int j = 0; j < t; j++)
                c[G[i]][G[j]] = c[G[j]][G[i]] = (i != j);
    }
    floyd();
    int ans = INF;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += c[i][j];
            if (sum > INF)
                sum = INF;
        }
        ans = min(ans, sum);
    }
    cout << ans * 100 / n << endl;
    return 0;
}
