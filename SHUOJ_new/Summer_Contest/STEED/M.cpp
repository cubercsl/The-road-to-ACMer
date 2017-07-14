#include <bits/stdc++.h>
using namespace std;
#define clr(a,x) memset(a, x, sizeof(a))
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;

#define lson rt << 1
#define rson rt << 1 | 1
#define Lson l, m, lson
#define Rson m + 1, r, rson
const int maxn = 1e5 + 5;
int MAX[maxn << 2]; // 历史变化最大值
int MIN[maxn << 2]; // 历史变化最小值
int val[maxn << 2]; // 实际变化值
int n, q;

void build(int l, int r, int rt)
{
    if (l == r)
    {
        cin >> val[rt];
        MAX[rt] = MIN[rt] = val[rt];
        return;
    }
    MAX[rt] = MIN[rt] = val[rt] = 0;
    int m = (l + r) >> 1;
    build(Lson);
    build(Rson);
}

void PushDown(int rt)
{
    if (val[rt] || MAX[rt] || MIN[rt])
    {
        MAX[lson] = max(MAX[lson], val[lson] + MAX[rt]);
        MIN[lson] = min(MIN[lson], val[lson] + MIN[rt]);
        MAX[rson] = max(MAX[rson], val[rson] + MAX[rt]);
        MIN[rson] = min(MIN[rson], val[rson] + MIN[rt]);
        val[lson] += val[rt];
        val[rson] += val[rt];
        MAX[rt] = MIN[rt] = val[rt] = 0;
    }
}

void update(int L, int R, int add, int l, int r, int rt)
{
    if (L <= l && r <= R)
    {
        val[rt] += add;
        MAX[rt] = max(MAX[rt], val[rt]);
        MIN[rt] = min(MIN[rt], val[rt]);
        return;
    }
    int m = (l + r) >> 1;
    PushDown(rt);
    if (L <= m) update(L, R, add, Lson);
    if (m < R) update(L, R, add, Rson);
}

int query(int k, int l, int r, int rt)
{
    if (l == r)
        return max(abs(MAX[rt]), abs(MIN[rt]));
    PushDown(rt);
    int m = (l + r) >> 1;
    if (k <= m) return query(k, Lson);
    else return query(k, Rson);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> q;
        build(1, n, 1);
        while (q--)
        {
            int cmd;
            cin >> cmd;
            if (cmd == 1)
            {
                int l, r, x;
                cin >> l >> r >> x;;
                update(l, r, x, 1, n, 1);
            }
            else
            {
                int k;
                cin >> k;
                cout << query(k, 1, n, 1) << endl;
            }
        }
    }
    return 0;
}
