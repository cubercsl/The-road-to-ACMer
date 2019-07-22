#include<bits/stdc++.h>
using namespace std;
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define lson_len (len - (len >> 1))
#define rson_len (len >> 1)

const int maxn = 1e5+5;
int sum[maxn << 2], lazy[maxn << 2];
vector<int> unsafe[maxn];
vector<pair<int,int> > safe[maxn];
int ans[maxn];

void build(int l,int r,int rt){
    lazy[rt] = 0;
    sum[rt] = 0;
    if(l == r){
        return ;
    }
    int m = l + r >> 1;
    build(l,m,lson);
    build(m+1,r,rson);
}
void pushdown(int rt,int len){
    if(!lazy[rt]) return ;
    int &x = lazy[rt];
    sum[lson] += x * lson_len;
    sum[rson] += x * rson_len;    
    lazy[lson] += x;
    lazy[rson] += x;
    x = 0;
}
void update(int l,int r,int rt,int L,int R, int x){
    if(l > r) return ;
    if(L <= l && R >= r){
        sum[rt] += x * (r - l + 1);
        lazy[rt] += x;
        return ;
    }
    pushdown(rt, r - l + 1);
    int m = l + r >> 1;
    if(L <= m) update(l,m,lson,L,R,x);
    if(m+1 <= R) update(m+1,r,rson,L,R,x);
    sum[rt] = sum[lson] + sum[rson];
}
int query(int l,int r,int rt,int L,int R){
    if(l > r) return 0;
    if(L <= l && R >= r){
        return sum[rt];
    }
    pushdown(rt, r - l + 1);
    int m = l + r >> 1, ret = 0;
    if(L <= m) ret += query(l,m,lson,L,R);
    if(m+1 <= R) ret += query(m+1,r,rson,L,R);
    return ret;
}

void solve(int n,int m){
    build(1,m,1);    
    for(int i=1;i<=n;i++){
        int l = 1,r = m;
        for(auto &v:unsafe[i]){
            update(1,m,1,l,v - 1,1);
            l = v + 1;
        }
        update(1,m,1,l,r,1);
        for(auto &v:safe[i]){
            auto it = upper_bound(unsafe[i].begin(),unsafe[i].end(),v.first);
            if(it == unsafe[i].end()) r = m + 1;
            else r = *it;
            if(it == unsafe[i].begin()) l = 0;
            else l = *(it-1);
            int tmp = query(1,m,1,l + 1,r - 1);
            ans[v.second] += tmp;
        }
    }
    build(1,m,1);
    for(int i=n;i>0;i--){
        int l,r;
        for(auto &v:safe[i]){
            auto it = upper_bound(unsafe[i].begin(),unsafe[i].end(),v.first);
            if(it == unsafe[i].end()) r = m + 1;
            else r = *it;
            if(it == unsafe[i].begin()) l = 0;
            else l = *(it-1);
            ans[v.second] += query(1,m,1,l + 1,r - 1);
        }
        l = 1, r = m;
        for(auto &v:unsafe[i]){
            update(1,m,1,l,v - 1,1);
            l = v + 1;
        }
        update(1,m,1,l,r,1);
    }
}

int main(){
    int T;
    scanf("%d",&T);
    while (T--) {
        int n,m,k,q;
        scanf("%d%d%d%d",&n,&m,&k,&q);
        for(int i=0;i<=n;i++) unsafe[i].clear(), safe[i].clear();
        for(int i=0,x,y;i<k;i++){
            scanf("%d%d",&x,&y);
            unsafe[x].push_back(y);
        }
        for(int i=0,x,y;i<q;i++){
            ans[i] = 0;
            scanf("%d%d",&x,&y);
            safe[x].push_back(make_pair(y,i));
        }
        solve(n,m);
        for(int i=0;i<q;i++) printf("%d\n",ans[i]);
    }
}