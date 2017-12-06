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

const int N = 1 << 10;
int v[N];

bool solve(int x, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            int a = v[i], b = v[j];
            int c = -a * x * x - b * x;
            if (binary_search(v, v + n, c)) return true;
        }
    return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, x;
    while (~scanf("%d%d", &n, &x))
    {
        for (int i = 0; i < n; i++)
            scanf("%d", v + i);
        sort(v, v + n);
        puts(solve(x, n) ? "YES" : "NO");
    }
    return 0;
}
