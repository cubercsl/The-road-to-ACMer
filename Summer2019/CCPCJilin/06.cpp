#include<bits/stdc++.h>
using namespace std;

int main(){
    int T,kase=1;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        int ans = 0;
        for(int i=0,x;i<n;i++){
            scanf("%d",&x);
            x = max(0, x-2);
            ans ^= x;
        } 
        printf("Case %d: %d\n",kase++,ans);
    }
}