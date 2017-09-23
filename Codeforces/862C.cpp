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
// freopen("1.in", "r", stdin);
// freopen("1.out", "w", stdout);
#endif
    int n, x;
    while (cin >> n >> x)
    {
        if (n == 1)
        {
            cout << "YES" << endl;
            cout << x << endl;
            continue;
        }
        if (n == 2)
        {
            if (x == 0)
                cout << "NO" << endl;
            else
                cout << "YES" << endl
                     << 0 << " " << x << endl;
            continue;
        }
        cout << "YES" << endl;
        int sum = 0;
        for (int i = 1; i < n - 2; i++)
        {
            sum ^= i;
            cout << i << " ";
        }
        if (sum ^ (n - 2) ^ x)
        {
            sum = (sum ^ (n - 2) ^ x);
            cout << n - 2 << " ";
        }
        else if (sum ^ (n - 2))
        {
            sum ^= x;
            cout << 0 << " ";
        }
        else
        {
            sum = (sum ^ (n - 1) ^ x);
            cout << n - 1<<" ";
        }
        for (int i = 100001;; i++)
            if ((sum ^ i) > (n - 1))
            {
                cout << i << " " << (sum ^ i) << endl;
                break;
            }
    }
    return 0;
}
