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

void work(int n)
{
    vector<int> v(n);
    for (auto& t : v) cin >> t;
    int p[4] = {0, 1, 1, 0};
    int s = 3;
    for (auto& t : v)
    {
        if (!p[t])
        {
            cout << "NO" << endl;
            return;
        }
        int w;
        for (int i = 1; i <= 3; i++)
            if (i != t && p[i]) p[w = i] ^= 1;
        p[s] ^= 1;
        s = w;
    }
    cout << "YES" << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    while (cin >> n)
        work(n);
    return 0;
}
