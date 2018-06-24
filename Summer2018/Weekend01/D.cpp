#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

#pragma optimize("-O3")

typedef long long ll;
typedef long double ld;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

#define my_sort_unique(c) (sort(c.begin(), c.end()), c.resize(distance(c.begin(), unique(c.begin(), c.end()))))
#define my_unique(a) a.resize(distance(a.begin(), unique(a.begin(), a.end())))
#define X first
#define Y second

void go();

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    go();
    return 0;
}

/****************************************************************************************************/

namespace io
{
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
}

struct Node
{
    int l, r, id;
};

int unit;

bool cmp(const Node& a, const Node& b)
{
    return a.l / unit < b.l / unit || a.l / unit == b.l / unit && a.r < b.r;
}

void update(int x, bool d, ll& tmp, VI& cnt)
{
    int& t = cnt[x];
    tmp -= 1LL * t * t * t;
    d ? ++t : --t;
    tmp += 1LL * t * t * t;
};

void go()
{
    int n;
    while (io::in(n))
    {
        VI a(n + 1);
        for (int i = 1; i <= n; i++) io::in(a[i]);
        VI b = a;
        my_sort_unique(b);
        for (int i = 1; i <= n; i++) a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();

        int m;
        io::in(m);
        vector<Node> q(m);
        for (int i = 0; i < m; i++) io::in(q[i].l), io::in(q[i].r), q[i].id = i;

        unit = sqrt((double)n);
        sort(q.begin(), q.end(), cmp);

        int l = 1, r = 0;
        ll tmp = 0;
        VI cnt(n + 1);
        VL ans(m);

        for (int i = 0; i < m; i++)
        {
            Node& t = q[i];
            while (t.l < l) update(a[--l], 1, tmp, cnt);
            while (t.l > l) update(a[l++], 0, tmp, cnt);
            while (t.r < r) update(a[r--], 0, tmp, cnt);
            while (t.r > r) update(a[++r], 1, tmp, cnt);
            ans[t.id] = tmp;
        }

        for (int i = 0; i < m; i++) io::out_int(ans[i]), io::out_char('\n');
    }
    io::write();
}