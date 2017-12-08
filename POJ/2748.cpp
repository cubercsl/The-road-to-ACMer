#include <algorithm>
#include <cstdio>
#include <vector>
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

int solve(vector<int> v)
{
    sort(v.begin(), v.end());
    int n = v.size();
    if (n == 2) return abs(v[1] - v[0]);
    int ans = INF;
    do
    {
        int m = n >> 1;
        if (v[0] == 0 || v[m] == 0) continue;
        int a = 0, b = 0;
        for (int i = 0; i < m; i++)
            (a *= 10) += v[i];
        for (int i = m; i < n; i++)
            (b *= 10) += v[i];
        ans = min(ans, abs(a - b));
    } while (next_permutation(v.begin(), v.end()));
    return ans;
}

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
        vector<int> v;
        int num;
        char c;
        while (~scanf("%d%c", &num, &c))
        {
            v.pb(num);
            if (c == '\n') break;
        }
        printf("%d\n", solve(v));
    }
    return 0;
}
