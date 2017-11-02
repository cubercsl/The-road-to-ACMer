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

int march[2105];
int nov[2105];

void init()
{
    march[2007] = 11, march[2008] = 9;
    int p = 2009, cnt = 0;
    while (p <= 2100)
    {
        march[p] = march[p - 1] - 1;
        if (cnt == 3) march[p]--;
        if (march[p] < 8) march[p] += 7;
        //cout << p << " " << march[p] << endl;
        cnt++, p++;
        cnt %= 4;
    }
    march[2100] = 14;
    nov[2007] = 4, nov[2008] = 2;
    p = 2009, cnt = 0;
    //  cout << "---" << endl;
    while (p <= 2100)
    {
        nov[p] = nov[p - 1] - 1;
        if (cnt == 3) nov[p]--;
        if (nov[p] < 1) nov[p] += 7;
        //cout << p << " " << nov[p] << endl;
        cnt++, p++;
        cnt %= 4;
    }
    nov[2100] = 7;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    init();
    int T, kase = 0;
    scanf("%d", &T);
    while (T--)
    {
        int ans = -1;
        int Y, M, D, h, m, s;
        scanf("%d-%d-%d %d:%d:%d", &Y, &M, &D, &h, &m, &s);
        if (M < 3 || M == 3 && D < march[Y] || M == 3 && D == march[Y] && h < 2)
            ans = 0;
        if (M > 11 || M == 11 && D > nov[Y] || M == 11 && D == nov[Y] && h >= 2)
            ans = 0;
        if (M > 3 && M < 11 || M == 3 && D > march[Y] || M == 3 && D == march[Y] && h >= 3 || M == 11 && D < nov[Y] || M == 11 && D == nov[Y] && h < 1)
            ans = 1;
        if (M == 3 && D == march[Y] && h == 2)
            ans = 2;
        if (M == 11 && D == nov[Y] && h == 1)
            ans = 3;
        assert(~ans);
        printf("Case #%d: ", ++kase);
        switch (ans)
        {
        case 0:
            puts("PST");
            break;
        case 1:
            puts("PDT");
            break;
        case 2:
            puts("Neither");
            break;
        case 3:
            puts("Both");
        }
    }
    return 0;
}
