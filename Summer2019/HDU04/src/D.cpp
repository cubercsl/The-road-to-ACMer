#include<bits/stdc++.h>
using namespace std;
#define lson (rt << 1)
#define rson (rt << 1 | 1)
const int maxn = 6e4+5;
typedef long long ll;
int a[maxn], n;
double seg[maxn << 2], lazy[maxn << 2];

inline void pushup(int rt){
    seg[rt] = min(seg[lson],seg[rson]);
}
inline void pushdown(int rt){
    if(lazy[rt] == 0) return ;
    double &x = lazy[rt];
    lazy[lson] += x;
    lazy[rson] += x;
    seg[lson] += x;
    seg[rson] += x;
    x = 0;
}
void build(int l,int r,int rt,double x){
    lazy[rt] = 0;
    if(l == r){
        seg[rt] = (l-1) * x;
        return ;
    }
    int m = l + r >> 1;
    build(l,m,lson,x);
    build(m+1,r,rson,x);
    pushup(rt);
}
void update(int l,int r,int rt,int L,int R,int x){
    if(L <= l && R >= r){
        seg[rt] += x;
        lazy[rt] += x;
        return ;
    }
    pushdown(rt);
    int m = l + r >> 1;
    if(L <= m) update(l,m,lson,L,R,x);
    if(m + 1 <= R) update(m+1,r,rson,L,R,x);
    pushup(rt);
}
double query(int l,int r,int rt,int L,int R){
    if(L <= l && R >= r){
        return seg[rt];
    }
    pushdown(rt);
    int m = l + r >> 1;
    double ret = LONG_LONG_MAX;
    if(L <= m) ret = min(ret, query(l,m,lson,L,R));
    if(m + 1 <= R) ret = min(ret, query(m+1,r,rson,L,R));
    return ret;
}
int last[maxn];
bool ok(double mid){
    build(1,n,1,mid);
    for(int i=1;i<=n;i++) last[i] = 0;
    for(int i=1;i<=n;i++){
        update(1,n,1,last[a[i]]+1,i,1);
        double tmp = query(1,n,1,1,i);
        if(tmp <= i * mid) return true;
        last[a[i]] = i;
    }
    return false;
}

const double eps = 1e-5;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",a+i);
        // ok(0.5);
        double l = 0, r = 1;
        double ans = -1;
        while(abs(l-r) >= eps){
            double mid = (l + r) / 2;
            if(ok(mid)){
                ans = mid;
                r = mid;
            } else{
                l = mid;
            }
        }
        printf("%.5f\n",ans);
    }
}