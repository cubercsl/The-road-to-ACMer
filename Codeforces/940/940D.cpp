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
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto& t : a) cin >> t;
    for (auto& t : b)
    {
        static char ch;
        cin >> ch;
        t = ch - '0';
    }
    int l = -1e9, r = 1e9;
    for (int i = 4; i < n; i++)
    {
        int aa = 0, bb = 0;
        for (int j = 1; j < 5; j++) aa += b[i - j] ^ 1, bb += b[i - j];
        if (aa == 4 && b[i] == 1)
            for (int j = 0; j < 5; j++) l = max(l, a[i - j] + 1);
        else if (bb == 4 && b[i] == 0)
            for (int j = 0; j < 5; j++) r = min(r, a[i - j] - 1);
    }
    cout << l << " " << r << endl;
    return 0;
}