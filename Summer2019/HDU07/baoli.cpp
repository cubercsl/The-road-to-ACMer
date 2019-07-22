#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
int ans;
void dfs(int i,int j, ll sum){
    if(j > k) return;
    if(i == n + 1){
        if(j <= k){
            for(ll t=2;t*t <= sum;t++){
                if(sum % (t * t) == 0){
                    return;
                }
            }
            ans++;
        }
        return;
    }
    dfs(i+1,j+1,sum * i);
    dfs(i+1,j,sum);
}
int main()
{
// #ifndef ONLINE_JUDGE
    // freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
// #endif
    while(~scanf("%d%d",&n,&k)){
        ans = 0;
        dfs(1,0,1);
        printf("%d\n",ans - 1);
    }
}