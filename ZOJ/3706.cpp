
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
    int t;
    cin >> t;
    while (t--)
    {
        int x, y;
        cin >> x >> y;
        int ans = 0;
        for (int i = 1; i <= x / 2; i++)
        {
            set<int> q;
            int a, b, c;
            a = i;
            b = x - i;
            c = y;
            q.insert(a);
            q.insert(b);
            q.insert(c);
            q.insert(a + b);
            q.insert(a + c);
            q.insert(b + c);
            q.insert(abs(a - b));
            q.insert(abs(a - c));
            q.insert(abs(c - b));
            q.insert(abs(a + b + c));
            q.insert(abs(a + b - c));
            q.insert(abs(a - b - c));
            q.insert(abs(a - b + c));
            q.insert(abs(b - a + c));
            q.insert(abs(b - a - c));
            q.insert(abs(c - b - a));
            int len = q.size();
            if (*q.begin() == 0)
                len--;
            ans = max(ans, len);
        }
        for (int i = 1; i <= y / 2; i++)
        {
            set<int> q;
            int a, b, c;
            a = i;
            b = y - i;
            c = x;
            q.insert(a);
            q.insert(b);
            q.insert(c);
            q.insert(a + b);
            q.insert(a + c);
            q.insert(b + c);
            q.insert(abs(a - b));
            q.insert(abs(a - c));
            q.insert(abs(c - b));
            q.insert(abs(a + b + c));
            q.insert(abs(a + b - c));
            q.insert(abs(a - b - c));
            q.insert(abs(a - b + c));
            q.insert(abs(b - a + c));
            q.insert(abs(b - a - c));
            q.insert(abs(c - b - a));
            int len = q.size();
            if (*q.begin() == 0)
                len--;
            ans = max(ans, len);
        }
        cout << ans << endl;
    }
    return 0;
}
