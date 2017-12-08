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
state st[MAXLEN << 1];
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

char buf[MAXLEN];
int pk[MAXLEN << 1], t[MAXLEN << 1];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    scanf("%s", buf);
    sa_init();
    int n = strlen(buf);
    for (int i = 0; i < n; i++) sa_extend(buf[i]);
    for (int i = 1; i < sz; i++) t[st[i].len]++;
    for (int i = 1; i <= n; i++) t[i] += t[i - 1];
    for (int i = sz - 1; i; i--) pk[t[st[i].len]--] = i;
    for (int i = 1; i < sz; i++) t[i] = st[i].len;
    while (~scanf("%s", buf))
    {
        static int tmp[MAXLEN];
        int n = strlen(buf);
        int v = 0, l = 0;
        for (int i = 0; i < n; i++)
        {
            while (v && !st[v].next.count(buf[i])) v = st[v].link, l = st[v].len;
            if (st[v].next.count(buf[i])) v = st[v].next[buf[i]], ++l;
            tmp[v] = max(tmp[v], l);
        }
        for (int i = sz - 1; i; i--)
        {
            int v = pk[i];
            t[v] = min(t[v], tmp[v]);
            if (tmp[v] && st[v].link) tmp[st[v].link] = st[st[v].link].len;
            tmp[v] = 0;
        }
    }
    int ans = 0;
    for (int i = 0; i < sz; i++) ans = max(t[i], ans);
    printf("%d\n", ans);
    return 0;
}
