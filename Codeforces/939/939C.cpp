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

const int N = 1 << 18;
int a[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, s, t;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) a[i + n] = a[i];
    cin >> s >> t;
    ll sum = 0;
    for (int i = 1; i <= t - s; i++) sum += a[i];
    ll ans = sum;
    int id = s;
    if (id == 0) id = n;
    for (int i = 2; i <= n; i++)
    {
        sum -= a[i - 1];
        sum += a[i + t - s - 1];
        if (sum > ans)
        {
            ans = sum;
            id = (s - (i - 1) + n) % n;
            if (id == 0) id = n;
        }
        else if (sum == ans)
        {
            int tmp = (s - (i - 1) + n) % n;
            if (tmp == 0) tmp = n;
            id = min(id, tmp);
        }
    }
    cout << id << endl;
    return 0;
}