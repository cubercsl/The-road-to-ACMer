// A Knight's Journey, POJ2488

/*Sample Input
3
1 1
2 3
4 3
*/

#include <iostream>
#include <cstring>
using namespace std;

int tx[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
int ty[8] = {-2, -2, -1, -1, 1, 1, 2, 2};

const char alp[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int p, q;
bool vis[26][26];
int ans[700];
bool flag;

void dfs(int x, int y, int dep)
{
    if (x < 0 || y < 0 || x >= p || y >= q)
        return;
    if (vis[x][y])
        return;
    vis[x][y] = 1;
    ans[dep] = x * q + y;
    if (dep == p * q)
    {
        if (!flag)
            for (int i = 1; i <= dep; i++)
                cout << alp[ans[i] % q] << ans[i] / q + 1;
        flag = 1;
        cout << endl;
        return;
    }

    for (int i = 0; i < 8; i++)
        dfs(x + tx[i], y + ty[i], dep + 1);
    vis[x][y] = 0;
}

int main()
{
    int n;
    int kase = 0;
    cin >> n;
    while (n--)
    {
        flag = 0;
        memset(vis, 0, sizeof(vis));
        cin >> p >> q;
        cout << "Scenario #" << ++kase << ":" << endl;
        dfs(0, 0, 1);
        if (!flag)
            cout << "impossible" << endl;
        cout << endl;
    }
}
