#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int dp[N][N][N];

int a[] = {1, 3, 7, 9};
int dfs(int x, int y, int z)
{
    if (~dp[x][y][z]) return dp[x][y][z];
    int& cur = dp[x][y][z];
    for (int i = 0; i < 4; i++)
    {
        if (x >= a[i] && !dfs(x - a[i], y, z)) return cur = 1;
        if (y >= a[i] && !dfs(x, y - a[i], z)) return cur = 1;
        if (z >= a[i] && !dfs(x, y, z - a[i])) return cur = 1;
    }
    return cur = 0;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int x, y, z;
    // while (cin >> x >> y >> z)
    // {
    //     for (int i = 0; i <= x; i++)
    //     {
    //         for (int j = 0; j <= y; j++)
    //         {
    //             for (int k = 0; k <= z; k++)
    //             {
    //                 dfs(i, j, k);
    //                 cout << dp[i][j][k];
    //             }
    //             cout << endl;
    //         }
    //         cout << endl;
    //     }
    while (cin >> x >> y >> z)
    {
        if (x <= 100 && y <= 100 && z <= 100)
        {
            if (dfs(x, y, z))
                cout << "win" << endl;
            else
                cout << "lose" << endl;
        }
    }
}