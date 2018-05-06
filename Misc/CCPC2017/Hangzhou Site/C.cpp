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

inline void gao(const vector<int>& v, int d)
{
    int n = v.size();
    int cnt = 0;
    for (auto& t : v) cnt += t == 1;
    if (d == 1) {
        if (cnt == n && n % 3 == 0)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
    else
    {
        if (cnt == n && n % 3 == 1)
            cout << "No" << endl;
        else if (cnt == n - 1)
        {
            if (n % 3 == 2)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
        else
            cout << "Yes" << endl;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T;
    cin >> T;
    while (T--)
    {
        int n, d;
        cin >> n >> d;
        vector<int> v(n);
        for (auto& t : v) cin >> t;
        gao(v, d);
    }
    return 0;
}