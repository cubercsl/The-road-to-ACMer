#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<vector<int>> a(n);
    int t = 0;
    for (int i = 0, m; i < n; i++)
    {
        scanf("%d", &m);
        for (int j = 0, x; j < m; j++)
        {
            scanf("%d", &x);
            a[i].push_back(x);
        }
        t = max(t, *max_element(a[i].begin(), a[i].end()));
    }
    long long ans = 0;
    for (int i = 0; i < n; i++)
        ans += 1LL * (t - *max_element(a[i].begin(), a[i].end())) * a[i].size();
    printf("%lld\n", ans);
}