// Oil Deposits, HDU1241
/*Sample Input
1 1
*
3 5
*@*@*
**@**
*@*@*
1 8
@@****@*
5 5 
****@
*@@*@
*@**@
@@@*@
@@**@
0 0 
*/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 105;

char pic[maxn][maxn];
int m, n, idx[maxn][maxn];

void dfs(int r, int c, int id)
{
    if (r < 0 || r >= m || c < 0 || c >= n)
        return;
    if (idx[r][c] > 0 || pic[r][c] != '@')
        return;
    idx[r][c] = id;
    for (int dr = -1; dr <= 1; dr++)
        for (int dc = -1; dc <= 1; dc++)
            if (dr || dc)
                dfs(r + dr, c + dc, id);
}

int main()
{
    while (cin >> m >> n, m + n)
    {
        memset(idx, 0, sizeof(idx));
        for (int i = 0; i < m; i++)
            cin >> pic[i];
        int cnt = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (!idx[i][j] && pic[i][j] == '@')
                    dfs(i, j, ++cnt);
        cout << cnt << endl;
    }
    return 0;
}