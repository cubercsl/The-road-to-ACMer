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
const ll mod = 1e9 + 7;
const double eps = 1e-6;

int main()
{
    ll x, y, F[6], n;
    while (    cin >> x >> y >> n)
    {
        F[1] = x;
        F[2] = y;
        F[3] = y - x;
        F[4] = -x;
        F[5] = -y;
        F[0] = x - y;
        cout << (F[n % 6] + 100 * mod) % mod << endl;
    }
    return 0;
}
