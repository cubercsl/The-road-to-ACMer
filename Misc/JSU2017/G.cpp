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

char s[55][55];
char c[] = "+-*/";

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int x = 0, y = 0, p = 0;
        bool flag = 0;
        s[x][y] = c[p];
        x++, y++;
        int tot = (1 + n) * n / 2;
        int cnt = 1, limit = n;
        for (int i = 1; i < tot; i++)
        {
            (++p) %= 4;
            // cout << x << " " << y << " " << p << endl;
            s[x][y] = c[p];
            cnt++;
            if (cnt == limit)
            {
                flag ^= 1, limit--, cnt = 0;
                if (flag)
                    y--;
                else
                    x++;
            }
            else if (flag)
                x--, y--;
            else
                x++, y++;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++)
                printf("%c%c", s[i][j], j == i ? '\n' : ' ');
        }
        puts("");
    }
    return 0;
}
