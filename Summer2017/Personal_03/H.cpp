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

const int maxn = 1010;
ll C[maxn][maxn];
int a[maxn];
void init()
{
    C[0][0] = 1;
    for (int i = 1; i < maxn; i++)
    {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
}

int main()
{
    init();
    int n;
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            a[i]--;
        }
        ll tmp = 1;
        ll ans = 1;
        for (int i = 0; i < n; i++)
        {
            ans = (ans * C[tmp + a[i] - 1][a[i]]) % mod;
            tmp += a[i] + 1;
        }
        cout << ans << endl;
    }
    return 0;
}
