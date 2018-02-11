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
    int n, m, num;
    while (~scanf("%d%d", &n, &m))
    {
        vector<int> a(n), b(m);
        vector<int> v;
        for (auto& t : a) scanf("%d", &t);
        for (auto& t : b) scanf("%d", &t);
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        for (auto& t : a)
            if (binary_search(b.begin(), b.end(), t))
                v.pb(t);
        if (v.empty())
            puts("empty");
        else
        {
            for (int i = 0; i < v.size(); i++)
            {
                if (i) printf(" ");
                printf("%d", v[i]);
            }
            puts("");
        }
    }
    return 0;
}