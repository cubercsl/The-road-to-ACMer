#include<bits/stdc++.h>
using namespace std;
const int maxn = 505;
int d[maxn],par[maxn],cnt[maxn];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,k;
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++) d[i] = cnt[i] =  0;
        for(int i=2,x;i<=n;i++){
            scanf("%d",&x);
            d[i]++;
            d[x]++;
            par[i] = x;
        }
        if((n & 1) ||(k < n - 1 - n / 2)){
            puts("Alice");
            continue;
        }
        bool flag = false;
        for(int i=1;i<=n;i++){
            if(d[i] == 1) cnt[par[i]]++;
        }
        for(int i=1;i<=n;i++){
            if(cnt[i] > 1) flag = true;
        }
        if(flag) puts("Alice");
        else puts("Bob");
    }
}