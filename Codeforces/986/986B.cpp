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

const int N = 1 << 20;
int bit[N];

ll sum(int x)
{
    ll t = 0;
    for (int i = x; i; i -= i & -i) t += bit[i];
    return t;
}

void update(int x)
{
    for (int i = x; i < N; i += i & -i) bit[i]++;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (auto& t : a) scanf("%d", &t);
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += i - sum(a[i]);
        update(a[i]);
    }
    ans = 7 * n + 1 - ans;
    puts(ans & 1 ? "Petr" : "Um_nik");
    return 0;
}
