#include <bits/stdc++.h>
using namespace std;

bool change[10][10];
bool vis[10];
int cnt[32];
int ans[32];
int anl = 1;

void dfs(int n, int id)
{
    if (vis[n])
        return;
    cnt[id]++;
    vis[n] = 1;
    for (int i = 1; i < 10; i++)
        if (change[n][i])
            dfs(i, id);
}

void mul(int ans[], int k)
{
    for (int i = 0; i < anl; i++)
        ans[i] *= k;
    for (int i = 0; i < anl; i++)
        if (ans[i] > 9)
        {
            ans[i + 1] += ans[i] / 10, ans[i] %= 10;
            if (i + 1 == anl)
                anl++;
        }
}

int main()
{
    int k;
    char n[32];
    ans[0] = 1;
    cin >> n >> k;
    int len = strlen(n);
    while (k--)
    {
        int a, b;
        cin >> a >> b;
        change[a][b] = 1;
    }
    for (int i = 0; i < len; i++)
    {
        memset(vis, 0, sizeof(vis));
        dfs(n[i] - '0', i);
        // cout<<cnt[i]<<endl;
        mul(ans, cnt[i]);
    }
    for (int i = anl - 1; i >= 0; i--)
        cout << ans[i];
    cout << endl;
    return 0;
}
