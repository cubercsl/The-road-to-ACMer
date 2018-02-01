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

int gao(int n)
{
    int ret = 0;
    do
        ret++;
    while (n /= 10);
    return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    // freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
#endif
    int n;
    while (~scanf("%d", &n))
    {
        int x = gao(n) - 1;
        int b = 1;
        for (int i = 0; i < x; i++)
            b *= 10;
        // cout << b << endl;
        for (int i = 1; i <= 10; i++)
        {
            if (b * i > n)
            {
                printf("%d\n", b * i - n);
                break;
            }
        }
    }

    return 0;
}
