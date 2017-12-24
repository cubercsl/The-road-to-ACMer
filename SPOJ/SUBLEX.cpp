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

template <class T>
inline bool scan_d(T& ret)
{
    char c;
    int sgn;
    if (c = getchar(), c == EOF) return 0; //EOF
    while (c != '-' && (c < '0' || c > '9')) c = getchar();
    sgn = (c == '-') ? -1 : 1;
    ret = (c == '-') ? 0 : (c - '0');
    while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + (c - '0');
    ret *= sgn;
    return 1;
}
inline void out(int x)
{
    if (x > 9) out(x / 10);
    putchar(x % 10 + '0');
}

const int maxn = 1 << 17;
struct SAM
{
    int len[maxn << 1], link[maxn << 1], ch[maxn << 1][26];
    int sz, rt, last;
    inline int newnode(int x = 0)
    {
        len[sz] = x;
        link[sz] = -1;
        clr(ch[sz], -1);
        return sz++;
    }
    inline void init() { sz = last = 0, rt = newnode(); }
    inline void extend(int c)
    {
        int np = newnode(len[last] + 1);
        int p;
        for (p = last; ~p && ch[p][c] == -1; p = link[p]) ch[p][c] = np;
        if (p == -1)
            link[np] = rt;
        else
        {
            int q = ch[p][c];
            if (len[p] + 1 == len[q])
                link[np] = q;
            else
            {
                int nq = newnode(len[p] + 1);
                memcpy(ch[nq], ch[q], sizeof(ch[q]));
                link[nq] = link[q], link[q] = link[np] = nq;
                for (; ~p && ch[p][c] == q; p = link[p]) ch[p][c] = nq;
            }
        }
        last = np;
    }
    int topcnt[maxn];
    int topsam[maxn << 1];
    int dp[maxn << 1];
    inline void sort(const int& n)
    {
        for (int i = 0; i < sz; i++) topcnt[len[i]]++;
        for (int i = 0; i < n; i++) topcnt[i + 1] += topcnt[i];
        for (int i = 0; i < sz; i++) topsam[--topcnt[len[i]]] = i;
        for (int i = sz - 1; i; i--)
        {
            int u = topsam[i];
            dp[u] = 1;
            for (int j = 0; j < 26; j++)
                if (~ch[u][j]) dp[u] += dp[ch[u][j]];
        }
    }
    inline void kth(int k, const int& n)
    {
        int u = rt;
        while (k > 0)
        {
            for (int i = 0; i < 26; i++)
                if (~ch[u][i])
                {
                    int v = ch[u][i];
                    if (dp[v] >= k)
                    {
                        --k, putchar('a' + i), u = v;
                        break;
                    }
                    else
                        k -= dp[v];
                }
        }
        puts("");
    }
};

SAM sam;
char s[maxn];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    scanf("%s", s);
    int n = strlen(s);
    sam.init();
    for (int i = 0; i < n; i++) sam.extend(s[i] - 'a');
    sam.sort(n);
    int q;
    scan_d(q);
    while (q--)
    {
        static int k;
        scan_d(k);
        sam.kth(k, n);
    }
    return 0;
}
