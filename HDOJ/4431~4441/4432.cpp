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

int gao(int n, int m)
{
    int ret = 0;
    do
        ret += (n % m) * (n % m);
    while (n /= m);
    return ret;
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
        ll sum = 0;
        for (int i = 1; i * i <= n; i++)
            if (n % i == 0)
            {
                if (n / i == i)
                    sum += gao(i, m);
                else
                    sum += gao(i, m) + gao(n / i, m);
            }
        vector<int> v;
        do
            v.pb(sum % m);
        while (sum /= m);
        reverse(v.begin(), v.end());
        for (auto t : v) printf("%c", t < 10 ? t + '0' : t - 10 + 'A');
        puts("");
    }
    return 0;
}
