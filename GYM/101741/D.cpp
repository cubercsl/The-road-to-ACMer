#include <bits/stdc++.h>
using namespace std;
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define lson_len (len - (len >> 1))
#define rson_len (len >> 1)
typedef long long ll;
const int maxn = 2e5+5;
int a[maxn],t[maxn];
int que[maxn],Max[maxn << 2];
int dp[maxn];
void build(int rt,int l,int r){
    if(l == r){
        Max[rt] = a[l];
        return;
    }
    int m = l + r >> 1;
    build(lson,l,m);
    build(rson,m+1,r);
    Max[rt] = max(Max[lson],Max[rson]);
}
int query(int rt,int l,int r,int L,int R){
    if(L <= l && R >= r) return Max[rt];
    int m = l + r >> 1;
    int ret = 0;
    if(m >= L) ret = max(ret, query(lson,l,m,L,R));
    if(m + 1 <= R) ret = max(ret, query(rson,m+1,r,L,R));
    return ret;
}
int cal(int j,int k){
    return dp[j] - dp[k] - t[j] + t[k];
}
int n;
int work(int j,int k,int i){
    return 2 * (query(1,1,n,j,i) - query(1,1,n,k,i));
}
int fuck(int j,int i){
    return dp[j] + max(t[i] - dp[j],0), + query(1,1,n,j,i) * 2;
}
int main()
{
    while (~scanf("%d", &n))
    {
        for (int i = 1; i <= n; i++)
            scanf("%d%d",t+i,a+i);
        build(1,1,n);
        int top = 0;
        for(int i=1;i<=n;i++){
            while(top > 1 && cal(que[top-1],que[top]) > cal(que[top], i)){
                top--;
            }
            que[++top] = i;
            int l = 1, r = top;
            int p;
            while(l <= r){
                int m = l + r >> 1;
                if(m > 1 && cal(que[m-1],que[m]) < work(que[m-1],que[m],i)){
                    p = m;
                    l = m + 1;
                }
                else if(m < top && cal(que[m],que[m+1]) < work(que[m],que[m+1],i)){
                    p = m;
                    r = m - 1;
                }
                else {
                    p = m;
                    break;
                }
            }
            dp[i] = min(fuck(que[1],i), fuck(que[top],i));
            dp[i] = min(dp[i],fuck(que[p],i));
        }
        printf("%d\n",dp[n]);
    }
}