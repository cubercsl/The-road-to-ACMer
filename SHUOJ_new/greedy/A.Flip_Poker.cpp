#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
char s[22];
bool c[22];
int ans;

void dfs(int i, int len, int m)
{
    if (i == len)
    {
        ans = min(ans, c[i - 1] ? INF : m);
        return;
    }
    if (c[i - 1])
    {
        c[i - 1] = !c[i - 1];
        c[i] = !c[i];
        c[i + 1] = !c[i + 1];
        m++;
    }
    dfs(i + 1, len, m);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    while (cin >> s)
    {
        ans = INF;
        int len = strlen(s);
        for (int i = 0; i < len; i++)
            c[i] = s[i] - '0';
        c[0] = (!c[0]), c[1] = (!c[1]);
        dfs(1, len, 1);
        for (int i = 0; i < len; i++)
            c[i] = s[i] - '0';
        dfs(1, len, 0);
        if (ans == INF)
            cout << "NO" << endl;
        else
            cout << ans << endl;
    }
    return 0;
}
