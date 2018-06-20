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
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        vector<int> v(n);
        multiset<int> s;
        for (auto& t : v) scanf("%d", &t);
        for (auto& t : v) s.insert(t);
        for (auto& t : v)
        {
            s.erase(s.find(t));
            int tmp = mod - t;
            auto p1 = s.lower_bound(tmp);
            auto p2 = s.rbegin();
            if (p1 != s.begin()) p1--;
            int ans = max((*p1 + t) % mod, (*p2 + t) % mod);
            printf("%d ", ans);
            s.insert(t);
        }
        puts("");
    }
    return 0;
}