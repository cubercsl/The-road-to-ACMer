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

const int N = 1 << 18;
ll v[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        static int c;
        cin >> c;
        q.push({c, i});
    }
    while (q.size() > 1)
    {
        pair<ll, int> a = q.top();
        q.pop();
        pair<ll, int> b = q.top();
        q.pop();
        if (a.X != b.X)
            v[a.Y] = a.X, q.push(b);
        else
        {
            v[a.Y] = -1;
            q.push({b.X * 2, b.Y});
        }
    }
    v[q.top().Y] = q.top().X;
    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (~v[i]) cnt++;
    cout << cnt << endl;
    for (int i = 0; i < n; i++)
        if (~v[i]) cout << v[i] << " ";
    return 0;
}