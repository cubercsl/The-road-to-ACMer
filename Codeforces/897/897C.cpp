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

string s = "What are you doing at the end of the world? Are you busy? Will you save us?";
string t = "What are you doing while sending \"\"? Are you busy? Will you send \"\"?";
ll f[1 << 17];
ll a = 34, b = 32, c = 2;

char gao(int n, ll k)
{
    if (n == 0)
        return k < s.length() ? s[k] : '.';
    if (k < a) return t[k];
    if (k < a + f[n - 1]) return gao(n - 1, k - a);
    if (k < a + f[n - 1] + b) return t[k - f[n - 1]];
    if (k < a + f[n - 1] + b + f[n - 1]) return gao(n - 1, k - a - f[n - 1] - b);
    if (k < f[n]) return t[k - 2 * f[n - 1]];
    return '.';
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int q;
    f[0] = (ll)s.length();
    ll d = t.length();
    for (int i = 1; i <= 100000; i++)
    {
        f[i] = 2 * f[i - 1] + d;
        if (f[i] > 1e18 + a)
            f[i] = 1e18 + a;
        // cout << f[i] << endl;
    }
    // printf("%u\n", t.size());
    cin >> q;
    while (q--)
    {
        int n;
        ll k;
        cin >> n >> k;
        --k;
        cout << gao(n, k);
    }
    return 0;
}