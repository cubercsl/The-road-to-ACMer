#include<bits/stdc++.h>
using namespace std;
#define lson rt << 1
#define rson rt << 1 | 1
const int maxn = 1e5+5;
const int INF = 0x3f3f3f3f;
int cnt[maxn], a[maxn], b[maxn], num[maxn];
int lazy[maxn << 2];
struct Node{
    int d,num,cnt,val;
    Node(int d=INF,int num=-1,int cnt=-1,int val=-1):d(d),num(num),cnt(cnt),val(val){}
    bool operator < (const Node &rhs) const{
        if(d == rhs.d) return val < rhs.val;
        return d < rhs.d;
    }
} seg[maxn << 2];

void pushup(int rt){
    seg[rt] = Node();
    if(seg[lson].cnt){
        seg[rt] = min(seg[rt], seg[lson]);
    }
    if(seg[rson].cnt){
        seg[rt] = min(seg[rt], seg[rson]);
    }
}
void pushdown(int rt){
    if(lazy[rt] == 0) return ;
    int &x = lazy[rt];
    lazy[lson] += x;
    lazy[rson] += x;
    seg[lson].num += x;
    seg[rson].num += x;
    seg[lson].d += x;
    seg[rson].d += x;
    x = 0;
}
void build(int l,int r,int rt){
    lazy[rt] = 0;
    if(l == r){
        seg[rt].cnt = cnt[l];
        seg[rt].num = num[l];
        seg[rt].d = num[l] - cnt[l];
        seg[rt].val = l;
        return ;
    }
    int m = l + r >> 1;
    build(l , m, lson);
    build(m+1,r,rson);
    pushup(rt);
}
void updatecnt(int l,int r,int rt,int p,int x){
    if(l == r){
        seg[rt].cnt += x;
        seg[rt].d = seg[rt].num - seg[rt].cnt;
        return ;
    }
    pushdown(rt);
    int m = l + r >> 1;
    if(p <=m ) updatecnt(l,m,lson,p,x);
    else updatecnt(m+1,r,rson,p,x);
    pushup(rt);
}

void updatenum(int l,int r,int rt,int L,int R,int x){
    if(L > R) return;
    if(L <= l && r <= R){
        seg[rt].num += x;
        seg[rt].d += x;        
        lazy[rt] += x;
        return ;
    }
    pushdown(rt);
    int m = l + r >> 1;
    if(m >= L) updatenum(l,m,lson,L,R,x);
    if(m + 1 <= R) updatenum(m+1,r,rson,L,R,x);
    pushup(rt);
}
void solve(int n){
    set<int> SET;
    for(int i=0;i<n;i++){
        if(cnt[a[i]] > n / 2) {
            puts("Impossible");
            return ;
        }
        SET.insert(a[i]);
        num[a[i]] = n - cnt[a[i]];
    }
    build(1,n,1);
    for(int i=0;i<n;i++){
        if(seg[1].d == 0 && seg[1].val != a[i]){
            b[i] = seg[1].val;
        }
        else{
            int tmp = -1;
            for(auto &v:SET){
                if(v == a[i]) continue;
                tmp = v;
                break;
            }
            assert(tmp != -1);
            b[i] = tmp;
        }
        updatecnt(1,n,1,b[i],-1);
        cnt[b[i]]--;
        if(cnt[b[i]] == 0) SET.erase(b[i]);
        updatenum(1,n,1,a[i]+1,n,-1);
        updatenum(1,n,1,1,a[i]-1,-1);
    }
    for(int i=0;i<n;i++){
        if(i) printf(" %d",b[i]);
        else printf("%d",b[i]);
    }
    puts("");
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) cnt[i] = num[i] = 0;
        for(int i=0;i<n;i++) scanf("%d",a+i), cnt[a[i]]++;
        solve(n);
    }
}
