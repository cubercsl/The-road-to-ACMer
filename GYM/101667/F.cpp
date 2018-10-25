#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
#define X first
#define Y second
PII dfs(int id, int n)
{
    if (n == 2)
    {
        if (id == 0) return make_pair(1, 1);
        if (id == 1) return make_pair(1, 2);
        if (id == 2) return make_pair(2, 2);
        if (id == 3) return make_pair(2, 1);
    }
    int a = id / (n * n / 4);
    int nid = id % (n * n / 4);
    PII no = dfs(nid, n / 2);
    PII ans;
    if (a == 0)
        ans.X = no.Y, ans.Y = no.X;
    else if (a == 1)
        ans.X = no.X, ans.Y = no.Y + n / 2;
    else if (a == 2)
        ans.X = no.X + n / 2, ans.Y = no.Y + n / 2;
    else if (a == 3)
        ans.X = n - no.Y + 1, ans.Y = n / 2 - no.X + 1;
    return ans;
}
int main()
{
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {
        PII ans = dfs(m - 1, n);
        printf("%d %d\n", ans.X, ans.Y);
    }
}