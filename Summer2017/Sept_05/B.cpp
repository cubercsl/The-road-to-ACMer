#include <bits/stdc++.h>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
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
const double eps = 1e-6;

const int N = 4000001;
ll phi[N] = {0, 1};
ll a[N];
ll dp[N];
void CalEuler()
{
    for (int i = 2; i < N; i++)
        if (!phi[i])
            for (int j = i; j < N; j += i)
            {
                if (!phi[j])
                    phi[j] = j;
                phi[j] = phi[j] / i * (i - 1);
            }
    for (int i = 1; i < N; i++)
    {
        for (int j = 2 * i; j < N; j += i)
            a[j] += phi[j / i] * i;
        dp[i] = dp[i - 1] + a[i];
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    CalEuler();
    int n;
    while (cin >> n, n)
        cout << dp[n] << endl;
    return 0;
}
