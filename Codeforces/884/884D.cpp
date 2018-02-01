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
    ll a, b, c;
    while (cin >> n)
    {
        priority_queue<ll, vector<ll>, greater<ll> > q;
        if (!(n & 1)) q.push(0);
        while (n--)
        {
            cin >> a;
            q.push(a);
        }
        ll sum = 0;
        while (q.size() > 1)
        {
            a = q.top();
            q.pop();
            b = q.top();
            q.pop();
            c = q.top();
            q.pop();
            sum += a + b + c;
            q.push(a + b + c);
        }
        cout << sum << endl;
    }
    return 0;
}
