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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    int cnt = 0;
    int aa = a, bb = b;
    for (int i = 0; i < n; i++)
    {
        if (s[i] != '.')
        {
            if (cnt & 1)
            {
                if (a > b)
                    a -= cnt / 2 + 1, b -= cnt / 2;
                else
                    a -= cnt / 2, b -= cnt / 2 + 1;
            }
            else
                a -= cnt / 2, b -= cnt / 2;
            cnt = 0;
        }
        else
            cnt++;
    }
    if (cnt & 1)
    {
        if (a > b)
            a -= cnt / 2 + 1, b -= cnt / 2;
        else
            a -= cnt / 2, b -= cnt / 2 + 1;
    }
    else
        a -= cnt / 2, b -= cnt / 2;
    cout << aa - max(a, 0) + bb - max(b, 0);
    return 0;
}