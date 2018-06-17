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

const int N = 1 << 17;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    auto Pow = [&](ll a, ll n) {
        ll t = 1;
        for (; n; n >>= 1, (a *= a) %= mod)
            if (n & 1) (t *= a) %= mod;
        return t;
    };
    vector<ll> f(N), inv(N);
    f[0] = 1;
    for (int i = 1; i < N; i++) f[i] = f[i - 1] * i % mod;
    inv[N - 1] = Pow(f[N - 1], mod - 2);
    for (int i = N - 2; ~i; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
    fastin int T;
    cin >> T;
    while (T--)
    {
        string s, t;
        cin >> s >> t;
        int n = s.length(), m = t.length();
        unordered_map<char, int> cnt;
        for (auto& ch : s) cnt[ch]++;
        for (auto& ch : t) cnt[ch]--;
        ll ans = n - m + 1;
        ans = ans * f[n - m] % mod;
        bool flag = false;
        for (auto& it : cnt)
        {
            if (it.Y < 0)
            {
                flag = true;
                break;
            }
            ans = ans * inv[it.Y] % mod;
        }
        if (flag)
            cout << 0 << endl;
        else
            cout << ans << endl;
    }
    return 0;
}
