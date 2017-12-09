#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int cnt, n;

void dfs(int cur)
{
    if (cur > n) return;
    if (cur == n)
    {
        cnt++;
        return;
    }
    dfs(cur + 2);
    dfs(cur + 1);
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cnt = 0;
        cin >> n;
        dfs(0);
        cout << cnt << endl;
    }
    return 0;
}
