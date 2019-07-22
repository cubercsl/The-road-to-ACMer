#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e3+5;
double dp[maxn];
const double eps = 1e-10;
double tmp[maxn];

void solve(int p){

    for(int i=1000;i<maxn;i++) dp[i] = 1000.0 / p;
    for(int i=999;i>=20;i--){
        dp[i] = 1000000  + (p * (1000 - i)) * dp[i + 20] + (1000 - p) * dp[i + 15] * 1000;
        dp[i] /= 1000000.0;
    }
    printf(" %.6f\n",dp[20]);
}
int main(){
    int T,kase = 1;
    scanf("%d",&T);
    while(T--){
        int p;
        scanf("%d",&p);
        p *= 10;
        printf("Case %d:",kase++);
        solve(p);
    }
}