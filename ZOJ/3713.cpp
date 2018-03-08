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

const int N = 3000005;
char s[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int t;
    scanf("%d", &t);
    getchar();
    while (t--)
    {
        gets(s);
        int n = strlen(s);
        do
            printf("%02X", (n & 127) + (n > 127 ? 128 : 0));
        while (n >>= 7);
        for (int i = 0; s[i]; i++)
            printf("%02X", s[i]);
        puts("");
    }
    return 0;
}
