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

const int N = 200000;
ll a[N];

inline ll f(int x)
{
    return 1LL * (4 * x - 5) * (x - 1) + 1;
}
inline ll g(int x)
{
    return 1LL * (4 * x - 9) * (x - 2);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    cin >> n;
    if (n == 1) return cout << 1 << endl, 0;

    a[0] = 1LL * (1 + n) * n / 2;
    a[n - 1] = 1LL * (5 * n - 3) * n / 2;
    for (int i = 1, x = n; i < n / 2; i++, x -= 2)
    {
        a[i] = a[i - 1] + f(x);
        a[n - i - 1] = a[n - i] + g(x);
    }
    if (n & 1)
        a[n / 2] = a[n / 2 - 1] + 15;
    for (int i = 0; i < n; i++)
        cout << a[i] << endl;

    return 0;
}
