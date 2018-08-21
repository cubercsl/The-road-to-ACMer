#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m;
    scanf("%d%d", &n, &m);
    vector<pair<int, int>> v;
    long double sum = 0;
    for (int i = 0, l, r; i < n; i++)
    {
        scanf("%d%d", &l, &r);
        v.emplace_back(l, 1);
        v.emplace_back(r + 1, -1);
        sum += r - l + 1;
    }
    sort(v.begin(), v.end());
    int ans = 0, cnt = 0;
    for (auto& t : v)
    {
        cnt += t.second;
        ans = max(ans, cnt);
    }
    printf("%d\n%.15Lf\n", ans, sum * 1.0 / m);
    return 0;
}