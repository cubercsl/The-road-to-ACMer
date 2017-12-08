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

struct state
{
    int len, link;
    map<char, int> next;
};

const int MAXLEN = 250000;
state st[MAXLEN * 2];
int sz, last;

void sa_init()
{
    sz = last = 0;
    st[0].len = 0;
    st[0].link = -1;
    ++sz;
}

void sa_extend(char c)
{
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    int p;
    for (p = last; p != -1 && !st[p].next.count(c); p = st[p].link)
        st[p].next[c] = cur;
    if (p == -1)
        st[cur].link = 0;
    else
    {
        int q = st[p].next[c];
        if (st[p].len + 1 == st[q].len)
            st[cur].link = q;
        else
        {
            int clone = sz++;
            st[clone].len = st[p].len + 1;
            st[clone].next = st[q].next;
            st[clone].link = st[q].link;
            for (; p != -1 && st[p].next[c] == q; p = st[p].link)
                st[p].next[c] = clone;
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}

char s[MAXLEN], t[MAXLEN];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    while (~scanf("%s%s", s, t))
    {
        sa_init();
        int n = strlen(s), m = strlen(t);
        for (int i = 0; i < n; i++) sa_extend(s[i]);
        int v = 0, l = 0, ans = 0;
        for (int i = 0; i < m; i++)
        {
            while (v && !st[v].next.count(t[i])) v = st[v].link, l = st[v].len;
            if (st[v].next.count(t[i])) v = st[v].next[t[i]], ++l;
            if (l > ans) ans = l;
        }
        printf("%d\n", ans);
    }
    return 0;
}
