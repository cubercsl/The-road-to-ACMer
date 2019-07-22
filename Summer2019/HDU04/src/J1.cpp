#include<bits/stdc++.h>
using namespace std;
const int maxn = 6e4+5;

map<int,map<int,int>> dp;
int a[maxn],b[maxn],n,k;
int ans ;
void dfs(int i,int j){
    if(i == n || j == n) {
        dp[i][j] = n - j + n - i;
        return ;
    }
    if(dp[i][j]) return ;

    int cnt = 0;
    while(i < n && j < n && abs(a[i] - b[j]) > k){
        cnt ++;
        i++;
        j++;
    }
    if(i == n || j == n) {
        dp[i - cnt][j - cnt] = n - j + n - i + cnt;
        return ;
    }
    int t1 = i, t2 = j;
    while(t1 < n && abs(a[t1] - b[j]) <= k){
        t1++;
    }
    dfs(t1,j);
    while(t2 < n && abs(a[i] - b[t2]) <= k){
        t2++;
    }
    dfs(i,t2);
    // printf("%d %d\n",dp[i][t2], dp[t1][j]);
    dp[i][j] = min(dp[i][t2] + t2 - j, dp[t1][j] + t1 - i) + cnt;
}
int main(){
    // freopen("1.in","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--){
        dp.clear();
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;i++) scanf("%d",a+i);
        for(int i=0;i<n;i++) scanf("%d",b+i);
        // int ans = min(solve(a,b,n,n), solve(b,a,n,n));
        dfs(0,0);
        printf("%d\n",dp[0][0]);
    }
}