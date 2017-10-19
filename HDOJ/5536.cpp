// Chip Factory, HDU5536

/*Sample Input
2
3
1 2 3
3
100 200 300
*/

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

const int MAXBUF = 10000;
char buf[MAXBUF], *ps = buf, *pe = buf + 1;
inline void rnext()
{
    if (++ps == pe)
        pe = (ps = buf) + fread(buf, sizeof(char), sizeof(buf) / sizeof(char), stdin);
}

template <class T>
inline bool in(T& ans)
{
    ans = 0;
    T f = 1;
    if (ps == pe) return false; //EOF
    do
    {
        rnext();
        if ('-' == *ps) f = -1;
    } while (!isdigit(*ps) && ps != pe);
    if (ps == pe) return false; //EOF
    do
    {
        ans = (ans << 1) + (ans << 3) + *ps - 48;
        rnext();
    } while (isdigit(*ps) && ps != pe);
    ans *= f;
    return true;
}

const int MAXOUT = 10000;
char bufout[MAXOUT], outtmp[50], *pout = bufout, *pend = bufout + MAXOUT;
inline void write()
{
    fwrite(bufout, sizeof(char), pout - bufout, stdout);
    pout = bufout;
}
inline void out_char(char c)
{
    *(pout++) = c;
    if (pout == pend) write();
}
inline void out_str(char* s)
{
    while (*s)
    {
        *(pout++) = *(s++);
        if (pout == pend) write();
    }
}
template <class T>
inline void out_int(T x)
{
    if (!x)
    {
        out_char('0');
        return;
    }
    if (x < 0) x = -x, out_char('-');
    int len = 0;
    while (x)
    {
        outtmp[len++] = x % 10 + 48;
        x /= 10;
    }
    outtmp[len] = 0;
    for (int i = 0, j = len - 1; i < j; i++, j--) swap(outtmp[i], outtmp[j]);
    out_str(outtmp);
}

int a[1005];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T;
    in(T);
    while (T--)
    {
        int n;
        in(n);
        for (int i = 0; i < n; i++)
            in(a[i]);
        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                for (int k = j + 1; k < n; k++)
                    ans = max((a[i] + a[j]) ^ a[k], ans),
                    ans = max((a[j] + a[k]) ^ a[i], ans),
                    ans = max((a[k] + a[i]) ^ a[j], ans);
        out_int(ans);
        out_char('\n');
    }
    write();
    return 0;
}
