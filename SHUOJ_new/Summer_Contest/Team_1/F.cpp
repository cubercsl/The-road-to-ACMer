#include <bits/stdc++.h>
using namespace std;
#define clr(a,x) memset(a, x, sizeof(a))
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int maxn = 15;
int f[maxn] = {1};

void init()
{
    for (int i = 1; i < maxn; i++)
        f[i] = i * f[i - 1];
}

int main()
{
#ifndef ONLINE_JUDGE
//    freopen("1.in", "r", stdin);
//    freopen("1.out", "w", stdout);
#endif

    init();
    int n;
    while (cin >> n, n >= 0)
    {
        if (!n)
        {
            puts("NO");
            continue;
        }
        for (int i = 10; ~i; i--)
            if (n >= f[i]) n -= f[i];
        puts(n == 0 ? "YES" : "NO");
    }


}
