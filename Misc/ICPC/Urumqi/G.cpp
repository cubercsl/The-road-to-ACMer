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

const int maxn = 1e5 + 5;
int co[maxn];
int v[maxn << 2];

#define lson rt << 1
#define rson rt << 1 | 1
#define Lson l, m, lson
#define Rson m + 1, r, rson

void pushup(int rt)
{
    v[rt] = v[lson] + v[rson];
}

void build(int l, int r, int rt)
{
    if (l == r)
    {
        v[rt] = co[l];
        return;
    }
    int m = (l + r) >> 1;
    build(Lson);
    build(Rson);
    v[rt] = v[lson] + v[rson];
}

void update(int p, int val, int l, int r, int rt)
{
    v[rt] += val;
    if (l == r)
        return;
    int m = (l + r) >> 1;
    if (p <= m)
        update(p, val, Lson);
    else
        update(p, val, Rson);
}

int query(int L, int R, int l, int r, int rt)
{
    if (L <= l && r <= R) return v[rt];
    int m = (l + r) >> 1;
    int sum = 0;
    if (L <= m)
        sum += query(L, R, Lson);
    if (m < R)
        sum += query(L, R, Rson);
    return sum;
}

char s[maxn], t[maxn];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
//    freopen("1.out", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, i, j, k;
        scanf("%d", &n);
        scanf("%s", s);
        scanf("%s", t);
        int slen = strlen(s);
        int tlen = strlen(t);
        clr(co, 0);
        for (i = tlen; i <= slen; i++)
        {
            for (j = i - tlen, k = 0; j < i; j++, k++)
            {
                if (s[j] != t[k])
                    break;
            }
            if (j == i) co[i] = 1;
        }
        build(1, slen, 1);
        char cmd[3];
        while (n--)
        {
            scanf("%s", cmd);
            if (cmd[0] == 'Q')
            {
                int l, r;
                scanf("%d%d", &l, &r);
                if (l + tlen - 1 > r)
                    puts("0");
                else
                    printf("%d\n", query(l + tlen - 1, r, 1, slen, 1));
            }
            else
            {
                int p;
                char c[3];
                scanf("%d%s", &p, c);
                s[p - 1] = c[0];
                for (i = max(p - tlen, 0); i < min(slen - tlen + 1, p); i++)
                {
                    for (j = i, k = 0; j < i + tlen; j++, k++)
                        if (s[j] != t[k])
                            break;
                    if (j < i + tlen)
                    {
                        if (co[i + tlen] == 1)
                        {
                            co[i + tlen] = 0;
                            update(i + tlen, -1, 1, slen, 1);
                        }
                    }
                    else
                    {
                        if (co[i + tlen] == 0)
                        {
                            co[i + tlen] = 1;
                            update(i + tlen, 1, 1, slen, 1);
                        }
                    }
                }
            }
        }
        puts("");
    }
    return 0;
}
