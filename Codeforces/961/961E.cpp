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
int a[N];
int bit[N];
void update(int x, int v)
{
    for (int i = x; i < N; i += i & -i) bit[i] += v;
}

int sum(int x)
{
    int t = 0;
    for (int i = x; i; i -= i & -i) t += bit[i];
    return t;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    priority_queue<PII> q;
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        while (!q.empty() && -(q.top().X) < i) update(q.top().Y, -1), q.pop();
        ans += sum(min(i - 1, a[i]));
        update(i, 1);
        q.push({-a[i], i});
    }

    cout << ans << endl;
    return 0;
}