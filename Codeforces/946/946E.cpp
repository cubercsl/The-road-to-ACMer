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
int bitmask[N];

void solve(const string& s)
{
    int n = s.length();
    assert(!(n & 1));
    bitmask[0] = 0;
    for (int i = 0; i < n; i++) bitmask[i + 1] = bitmask[i] ^ (1 << s[i] - '0');
    for (int i = s.length() - 1; ~i; i--)
    {
        int up = s[i] - '0';
        for (int j = up - 1; ~j; j--)
        {
            if (i == 0 && j == 0) continue; // 前导零
            int cur = bitmask[i] ^ (1 << j);
            int cnt = __builtin_popcount(cur);
            if (s.length() - i > cnt)
            {
                for (int k = 0; k < i; k++) cout << s[k];
                cout << j;
                int tot = s.length() - i - 1 - cnt;
                while (tot--) cout << 9;
                for (int k = 9; ~k; k--)
                    if (cur >> k & 1) cout << k;
                cout << endl;
                return;
            }
        }
    }
    for(int i =0; i < s.length() - 2; i++) cout << 9;
    cout << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        solve(s);
    }
    return 0;
}