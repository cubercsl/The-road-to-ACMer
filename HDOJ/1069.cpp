// Monkey and Banana, HDU1069

/*Sample Input
1
10 20 30
2
6 8 10
5 5 5
7
1 1 1
2 2 2
3 3 3
4 4 4
5 5 5
6 6 6
7 7 7
5
31 41 59
26 53 58
97 93 23
84 62 64
33 83 27
0
*/

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

const int maxn = 105;

struct node
{
    int a, b, c;
    bool operator < (const node &rhs) const
    {
        return a * b < rhs.a * rhs.b;
    }
    node(int _a, int _b, int _c)
    {
        if (_a > _b)
            swap(_a, _b);
        a = _a, b = _b, c = _c;
    }
};

vector <node> v;

int dp[maxn];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin
    int n;
    int kase = 0;
    while (cin >> n, n)
    {
        v.clear();
        while (n--)
        {
            int a, b, c;
            cin >> a >> b >> c;
            v.pb(node(a, b, c));
            v.pb(node(b, c, a));
            v.pb(node(c, a, b));
        }
        sort(v.begin(), v.end());
        clr(dp, 0);
        int ans = 0;
        for (int i = 0; i < v.size(); i++)
        {
            int tmp = 0;
            for (int j = 0; j < i; j++)
                if ((v[i].a > v[j].a) && (v[i].b > v[j].b))
                    tmp = max(tmp, dp[j]);
            dp[i] = tmp + v[i].c;
            ans = max(ans, dp[i]);
        }
        cout << "Case " << ++kase << ": maximum height = " << ans << endl;
    }
    return 0;
}
