#include<bits/stdc++.h>
using namespace std;
#define lson (rt << 1)
#define rson (rt << 1 | 1)

struct line{
    int l,r,w,y;
    bool operator < (const line& rhs) const{
        return y < rhs.y;
    }
};
vector<int> a;
inline int getid(int x){
    return lower_bound(a.begin(),a.end(),x) - a.begin() + 1;
}

const int maxn = 1e6;
int sum[maxn << 2];

void update(int l,int r,int rt,int p,int x){
    if(l == r){
        sum[rt] += x;
        return ;
    }
    int m = l + r >> 1;
    if(p <= m) update(l,m,lson,p,x);
    else update(m+1,r,rson,p,x);
    sum[rt] = sum[lson] + sum[rson];
}
int query(int l,int r,int rt,int L,int R){
    if(L <= l && R >= r) return sum[rt];
    int m = l + r >> 1;
    int ret = 0;
    if(m >= L) ret += query(l,m,lson,L,R);
    if(m+1 <= R) ret += query(m+1,r,rson,L,R);
    return ret;
}
int main(){
    int n;
    scanf("%d",&n);
    vector<line> lines;
    for(int i=0,x1,y1,x2,y2;i<n;i++){
        scanf("%d%d",&x1,&y1);
        scanf("%d%d",&x2,&y2);
        lines.push_back({x1,x2,1,y1});
        lines.push_back({x1,x2,-1,y2});
        a.push_back(x1);
        a.push_back(x2);
        a.push_back(y1);
        a.push_back(y2);
    }
    sort(a.begin(),a.end());
    a.resize(distance(a.begin(),unique(a.begin(),a.end())));
    int N = a.size();
    // /*
    for(auto &v:lines){
        v.l = getid(v.l);
        v.r = getid(v.r);
        v.y = getid(v.y);
    }
    // */
    sort(lines.begin(),lines.end());
    bool flag = false;
    for(auto v:lines){
        if(v.w == 1){
            if (query(1, N ,1, v.l, v.r) == 0){
                update(1, N ,1 , v.l, v.w);
                update(1, N ,1 , v.r, v.w);
            } else{
                flag = true;
                break;
            }
        } else{
            if (query(1, N ,1, v.l, v.r) == 2){
                update(1, N ,1 , v.l, v.w);
                update(1, N ,1 , v.r, v.w);
            } else{
                flag = true;
                break;
            }
        }
    }
    if(flag) puts("1");
    else puts("0");

}