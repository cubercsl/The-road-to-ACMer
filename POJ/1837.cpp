// Balance, POJ1837

/*Sample Input
2 4
-2 3 
3 4 5 8
*/

#include <iostream>
using namespace std;

const int INF = 0x3f3f3f3f;
int dp[25][20000];
int g[25],c[25];
int n,m;

void solve()
{
    dp[0][7500]=1;
    for(int i=1;i<=m;i++)
        for(int j=0;j<=15000;j++)
            for(int k=1;k<=n;k++)
                dp[i][j]+=dp[i-1][j+g[i]*c[k]];
    cout<<dp[m][7500]<<endl;
}


int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>c[i];
    for(int i=1;i<=m;i++)
        cin>>g[i];
    solve();
	return 0;
}

