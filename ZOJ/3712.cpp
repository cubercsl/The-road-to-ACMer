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

const int b[] = {300, 100, 50};
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
        int a[3];
        int Max = 0, Min = 0;
        for (int i = 0; i < 3; i++)
            cin >> a[i];
        int c = 0;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < a[i]; j++)
                Min += b[i] * (c++ * 2 + 1);
        c = 0;
        for (int i = 2; ~i; i--)
            for (int j = 0; j < a[i]; j++)
                Max += b[i] * (c++ * 2 + 1);
        cout << Min << " " << Max << endl;
    }
    return 0;
}
