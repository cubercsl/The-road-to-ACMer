#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3+5;
double dp[maxn][maxn];
const double eps = 1e-6;

void solve(int p){
    int n = 1000;
    for(int i=0;i<n;i++)
        for(int j=0;j<=1000;j++) 
            dp[i][j] = 0;
    dp[0][20] = 1;

    for(int i=1;i<n;i++){
        for(int j=15;j<=1000;j++){
            // dp[i][j] = dp[i-1][j-20] * (p / 100.0) * (1 - (j-20) / 1000.0) + dp[i-1][j-15] * (1 - p / 100.0);
            dp[i][j] = dp[i-1][j-20] * p * (1000 - (j-20)) / 1000.0 + dp[i-1][j-15] * (100 - p) ;
            dp[i][j] /= 100.0;
        }
    }
    double ans = 0;
    for(int i=0;i<n;i++){
        double sum = 0;
        for(int j=0;j<=1000;j++){
            // ans += (i + 1) * dp[i][j] * (p / 100.0) * (j / 1000.0);
            sum += dp[i][j] * j;
        }
        ans += (i + 1) * sum * p; 
    }
    printf(" %.10f\n",ans / 100000.0);
}
int main(){
    int T,kase = 1;
    scanf("%d",&T);
    while(T--){
        int p;
        scanf("%d",&p);
        printf("Case %d:",kase++);
        solve(p);
    }
}