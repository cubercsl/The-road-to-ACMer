#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    vector<pii> a;
    pii x;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &x.first, &x.second);
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    int l = 0, r = 0;
    int ans = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i].first > r)
        {
            ans += (r - l) * 2;
            l = a[i].first;
            r = a[i].second;
        }
        else
        {
            r = max(r, a[i].second);
        }
    }
    ans += (r - l) * 2 + n + 1;
    printf("%d\n", ans);
}