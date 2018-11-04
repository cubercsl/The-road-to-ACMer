#include <bits/stdc++.h>
using namespace std;
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define lson_len (len - (len >> 1))
#define rson_len (len >> 1)
typedef long long ll;
typedef pair<ll, ll> pll;
const ll INF = 1e18;
const ll NINF = -1e18;
const int maxn = 1e5 + 5;
struct Node
{
    pll mx, dx, mi, di;
    Node(pll mx = {NINF, -1}, pll dx = {NINF, -1}, pll mi = {INF, -1}, pll di = {INF, -1}) : mx(mx), dx(dx), mi(mi), di(di) {}
};
struct Seg
{
    Node X, Y;
} seg[maxn << 2];

inline Node cal(const Node& A, const Node& B)
{
    Node ret;
    ret.mx = max(A.mx, B.mx);
    if (ret.mx.second != A.mx.second) ret.dx = max(ret.dx, A.mx);
    if (ret.mx.second != A.dx.second) ret.dx = max(ret.dx, A.dx);
    if (ret.mx.second != B.mx.second) ret.dx = max(ret.dx, B.mx);
    if (ret.mx.second != B.dx.second) ret.dx = max(ret.dx, B.dx);

    ret.mi = min(A.mi, B.mi);
    if (ret.mi.second != A.mi.second) ret.di = min(ret.di, A.mi);
    if (ret.mi.second != A.di.second) ret.di = min(ret.di, A.di);
    if (ret.mi.second != B.mi.second) ret.di = min(ret.di, B.mi);
    if (ret.mi.second != B.di.second) ret.di = min(ret.di, B.di);

    return ret;
}
inline void pushup(int rt)
{
    seg[rt].X = cal(seg[lson].X, seg[rson].X);
    seg[rt].Y = cal(seg[lson].Y, seg[rson].Y);
}
void build(int l, int r, int rt)
{
    if (l == r)
    {
        int x, y, c;
        scanf("%d%d%d", &x, &y, &c);
        seg[rt].X.mx = seg[rt].X.mi = {x + y, c};
        seg[rt].Y.mx = seg[rt].Y.mi = {x - y, c};
        seg[rt].X.dx = seg[rt].Y.dx = {NINF, -1};
        seg[rt].X.di = seg[rt].Y.di = {INF, -1};
        return;
    }
    int m = l + r >> 1;
    build(l, m, lson);
    build(m + 1, r, rson);
    pushup(rt);
}

void update_val(int l,int r,int rt,int p,int x,int y){
    if(l == r){
        pll v1 = {seg[rt].X.mx.first + x + y, seg[rt].X.mx.second};
        seg[rt].X.mx = seg[rt].X.mi = v1;
        pll v2 = {seg[rt].Y.mx.first + x - y, seg[rt].Y.mx.second};
        seg[rt].Y.mx = seg[rt].Y.mi = v2;
        return;
    }
    int m = l + r >> 1;
    if (p <= m) update_val(l, m, lson, p, x, y);
    else
        update_val(m + 1, r, rson, p, x, y);
    pushup(rt);
}
void update_col(int l,int r,int rt,int p,int c){
    if(l == r){
        pll v1 = {seg[rt].X.mx.first,c};
        seg[rt].X.mx = seg[rt].X.mi = v1;
        pll v2 = {seg[rt].Y.mx.first,c};
        seg[rt].Y.mx = seg[rt].Y.mi = v2;
        return;
    }
    int m = l + r >> 1;
    if (p <= m) update_col(l, m, lson, p, c);
    else
        update_col(m + 1, r, rson, p, c);
    pushup(rt);
}
Seg query(int l,int r,int rt,int L,int R){
    if(L <= l && r <= R){
        return seg[rt];
    }
    int m = l + r >> 1;
    if (m < L) return query(m + 1, r, rson, L, R);
    else if(m >= R)
        return query(l, m, lson, L, R);
    else{
        Seg s1 = query(l, m, lson, L, R);
        Seg s2 = query(m + 1, r, rson, L, R);
        Seg ret;
        ret.X = cal(s1.X, s2.X);
        ret.Y = cal(s1.Y, s2.Y);
        return ret;
    }
}

int main(){
    int T,kase = 1;
    scanf("%d", &T);
    while(T--){
        int n, m;
        scanf("%d%d", &n, &m);
        build(1, n, 1);
        printf("Case #%d:\n", kase++);
        int op,l,r,k,c,x,y;
        while(m--){
            scanf("%d", &op);
            if(op == 1){
                scanf("%d%d%d", &k, &x, &y);
                update_val(1, n, 1, k, x, y);
            }
            else if(op == 2){
                scanf("%d%d", &k, &c);
                update_col(1, n, 1, k, c);
            }
            else{
                scanf("%d%d", &l, &r);
                Seg res = query(1, n, 1, l, r);
                ll ans = 0;
                if(res.X.mx.second != res.X.mi.second)
                    ans = max(ans, res.X.mx.first - res.X.mi.first);
                else {
                    if (res.X.dx.second != -1)
                        ans = max(ans, res.X.dx.first - res.X.mi.first);
                    if(res.X.di.second != -1)
                        ans = max(ans, res.X.mx.first - res.X.di.first);
                }
                if(res.Y.mx.second != res.Y.mi.second)
                    ans = max(ans, res.Y.mx.first - res.Y.mi.first);
                else {
                    if (res.Y.dx.second != -1)
                        ans = max(ans, res.Y.dx.first - res.Y.mi.first);
                    if(res.Y.di.second != -1)
                        ans = max(ans, res.Y.mx.first - res.Y.di.first);
                }
                printf("%lld\n", ans);
            }
        }
    }
}