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

const int maxn = 1e6 + 5;
int n, x, prime[maxn], tot, mu[maxn];
ll diri[maxn];
bool check[maxn];
void calmu()
{
    mu[1] = 1;
    for (int i = 2; i < maxn; i++)
    {
        if (!check[i]) prime[tot++] = i, mu[i] = -1;
        for (int j = 0; j < tot; j++)
        {
            if (i * prime[j] >= maxn) break;
            check[i * prime[j]] = true;
            if (i % prime[j] == 0)
            {
                mu[i * prime[j]] = 0;
                break;
            }
            else
                mu[i * prime[j]] = -mu[i];
        }
    }
}
int phi[maxn] = {0, 1};
void CalEuler()
{
    for (int i = 2; i < maxn; i++)
        if (!phi[i])
            for (int j = i; j < maxn; j += i)
            {
                if (!phi[j]) phi[j] = j;
                phi[j] = phi[j] / i * (i - 1);
            }
}

void init()
{
    for (int i = 1; i < maxn; i++) diri[i] = 1;
    for (int i = 2; i < maxn; i++)
    {
        for (int j = i; j < maxn; j += i)
            diri[j] += i * mu[i];
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    calmu();
    CalEuler();
    init();
    ll n;
    while (cin >> n)
    {
        ll ans = (n * n * phi[n] * 2 + n * diri[n]) / 6;
        cout << ans << endl;
    }
    return 0;
}
