#include <bits/stdc++.h>
using namespace std;

struct Node
{
    // a: own
    // b: opp
    int a[5], b[5];
    Node() {}
    Node(const int* _a, const int* _b)
    {
        memcpy(a, _a, sizeof(a));
        memcpy(b, _b, sizeof(b));
        sort(a, a + 5, greater<int>());
        sort(b, b + 5, greater<int>());
    }
    int operator()()
    {
        sort(a, a + 5, greater<int>());
        sort(b, b + 5, greater<int>());
        int ret = 0;
        for (int i = 4; ~i; i--) (ret *= 7) += a[i];
        for (int i = 4; ~i; i--) (ret *= 7) += b[i];
        return ret;
    }
};


map<int, double> dp;
int sum, d;

double dfs(Node u)
{
    int x = u();
    if (dp.count(x)) return dp[x];
    int n = 0, m = 0;
    int now = 0;
    for (int i = 0; i < 5; i++)
    {
        if (u.a[i]) n++;
        if (u.b[i]) m++;
        now += u.a[i] + u.b[i];
    }
    if (m == 0) return dp[x] = 1;
    if (sum - now == d) return dp[x] = 0;
    double ret = 0;
    for (int i = 0; i < n; i++)
    {
        Node v = u;
        v.a[i]--;
        ret += dfs(v);
    }
    for (int i = 0; i < m; i++)
    {
        Node v = u;
        v.b[i]--;
        ret += dfs(v);
    }
    ret /= (m + n);
    return dp[x] = ret;
}

int main()
{
    int n, m, d;
    scanf("%d%d%d", &n, &m, &d);
    ::d = d;
    int a[5] = {0}, b[5] = {0};
    for (int i = 0; i < n; i++) scanf("%d", a + i), sum += a[i];
    for (int i = 0; i < m; i++) scanf("%d", b + i), sum += b[i];
    Node x(a, b);
    printf("%.8f\n", dfs(x));

}