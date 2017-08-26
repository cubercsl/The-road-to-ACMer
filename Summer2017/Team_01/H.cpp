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

const int MAXN = 1e7 + 5;
bool vis[MAXN];
int tot, phi[MAXN], prime[MAXN];
void CalPhi(int n)
{
    clr(vis, 0);
    phi[1] = 1;
    tot = 0;
    for (int i = 2; i < n; i++)
    {
        if (!vis[i])
        {
            prime[tot++] = i;
            phi[i] = i - 1;
        }
        for (int j = 0; j < tot; j++)
        {
            if (i * prime[j] > n) break;
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0)
            {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
            else phi[i * prime[j]] = phi[i] * (prime[j] - 1);
        }
    }
}

ll a[MAXN];

int main()
{
    int n;
    cin >> n;
    CalPhi(n);
    a[1] = 1;
    for (int i = 2; i <= n; i++)
        a[i] = a[i - 1] + 2 * phi[i];
    ll ans = 0;
    for (int i = 0; i < tot; i++)
        if (n / prime[i])
            ans += a[n / prime[i]];
    cout << ans << endl;
    return 0;
}

