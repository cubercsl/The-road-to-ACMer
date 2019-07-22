#include<bits/stdc++.h>
using namespace std;
const int maxn = 6e4+5;

int a[maxn],b[maxn],k;
int solve(int a[],int b[],int n,int m){
    int i=0,cnt=0;
    for(int j=0;j<m && i<n;j++){
        if(abs(a[i] - b[j]) > k){
            cnt++;
            i++;
        }
    }
    int sum = cnt + n - cnt + m - cnt;
    return sum;
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;i++) scanf("%d",a+i);
        for(int i=0;i<n;i++) scanf("%d",b+i);
        int ans = min(solve(a,b,n,n), solve(b,a,n,n));
        printf("%d\n",ans);
    }
}