// Billboard, HDU2795

/*Sample Input
3 5 5
2
4
3
3
3
*/

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
const int maxn = 2e5 + 5;
#define lson rt << 1
#define rson rt << 1 | 1
#define Lson l, m, lson
#define Rson m + 1, r, rson
int seg[maxn << 2];
int h, w, n;
void PushUp(int rt)
{
    seg[rt] = max(seg[lson], seg[rson]);
}

void build(int l, int r, int rt)
{
    if (l == r)
    {
        seg[rt] = w;
        return;
    }
    int m = (l + r) >> 1;
    build(Lson);
    build(Rson);
    PushUp(rt);
}

int query(int x, int l, int r, int rt)
{
    int m = (l + r) >> 1, ans = 0;
    if (l == r)
    {
        seg[rt] -= x;
        return l;
    }
    if (seg[lson] >= x) ans = query(x, l, m, lson);
    else ans = query(x, m + 1, r, rson);
    PushUp(rt);
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin
    while (cin >> h >> w >> n)
    {
        h = min(h, n);
        clr(seg, 0);
        build(1, h, 1);
        while (n--)
        {
            int a;
            cin >> a;
            if (seg[1] < a)
                cout << -1 << endl;
            else
                cout << query(a, 1, h, 1) << endl;
        }
    }
    return 0;
}
