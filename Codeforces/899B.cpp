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

int a[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int c[26];
bool ok(int n)
{
    for (int i = 0; i < 24; i++)
    {
        int cnt = 0;
        int j, k = i;
        for (j = 0; j < n; j++)
        {
            if (c[j] == 29 && a[k] == 28)
            {
                cnt++;
                k = (k + 1) % 24;
                continue;
            }
            if (a[k] != c[j]) break;
            k = (k + 1) % 24;
        }
        if (j == n && cnt != 2) return true;
    }
    return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    while (~scanf("%d", &n))
    {
        for (int i = 0; i < n; i++) scanf("%d", c + i);
        puts(ok(n) ? "YES" : "NO");
    }

    return 0;
}
