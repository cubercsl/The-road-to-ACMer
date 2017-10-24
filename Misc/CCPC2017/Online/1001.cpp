#include <bits/stdc++.h>
using namespace std;
#define clr(a,x) memset(a, x, sizeof(a))
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;

vector <PII> v;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n = 44;
    int now = n;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < n / i; j++)
        {
            now++;
            for (int k = 1; k <= i; k++)
                v.pb(mp(now, i * j + k));
        }
    }
    cout << now << " " << v.size() << endl;
    for (auto a : v) cout << a.X << " " << a.Y << endl;
    cout << n << endl;
    for (int i = 1; i <= n; i++) cout << i << endl;
    return 0;
}
