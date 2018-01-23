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
    int c;
    cin >> c;
    if (c < 4 || c & 1)
        cout << -1 << endl;
    else
    {
        cout << 4 << endl;
        cout << "0 1" << endl;
        cout << "0 0" << endl;
        cout << (c - 2) / 2 << " 0" << endl;
        cout << (c - 2) / 2 << " 1" << endl;
    }
    return 0;
}
