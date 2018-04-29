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

void judge(const vector<int>& a, int b)
{
    for (auto& t : a)
        if ((t + b) % 7 == 0)
        {
            cout << "Yes" << endl;
            return;
        }
    cout << "No" << endl;
    return;
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
        int n, b;
        cin >> n >> b;
        vector<int> a(n);
        for (auto& t : a) cin >> t;
        judge(a, b);
    }
    return 0;
}
