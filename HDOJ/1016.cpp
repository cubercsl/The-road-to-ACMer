// Prime Ring Problem HDU1016

/*Sample Input
6
8
*/

#include <bits/stdc++.h>
using namespace std;

int n;
bool vis[22];
int ans[22];

bool isPrime(int n)
{
    int m = sqrt(n);
    for (int i = 2; i <= m; i++)
        if (n % i == 0)
            return false;
    return true;
}

void dfs(int now, int dep)
{
    if (vis[now])
        return;
    if (!isPrime(now + ans[dep - 1]))
        return;
    if (dep == n)
        if (!isPrime(now + ans[1]))
            return;
        else
        {
            ans[dep] = now;
            cout << 1;
            for (int i = 2; i <= n; i++)
                cout << " " << ans[i];
            cout << endl;
            return;
        }
    // 判断是否符合条件，符合做标记并深搜，不符合回溯
    ans[dep] = now;
    vis[now] = 1;
    for (int i = 2; i <= n; i++)
        dfs(i, dep + 1);
    vis[now] = 0;
    // 回溯时删除标记
}

int main()
{
    int kase = 0;
    while (cin >> n)
    {
        cout << "Case " << ++kase << ":" << endl;
        memset(vis, 0, sizeof(vis));
        ans[0] = 1;
        dfs(1, 1);
        cout << endl;
    }
    return 0;
}
