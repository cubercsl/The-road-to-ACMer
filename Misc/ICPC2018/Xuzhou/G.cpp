#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
typedef long long ll;

int main()
{
    int n;
    scanf("%d", &n);
    vector<pair<int, int> > vec;
    for (int i = 0, x, y; i < n; i++)
    {
        scanf("%d%d", &x, &y);
        vec.emplace_back(x, y);
    }
    set<pair<int, int> > s, ss;
    s.insert({0, INF});
    s.insert({INF, 0});
    ll ans = 0;
    reverse(vec.begin(), vec.end());
    for (auto& point : vec)
    {
        if (ss.find(point) != ss.end()) continue;
        ss.insert(point);
        auto p = s.lower_bound(point);
        auto q = p;
        --q;
        if (point.second > p->second && point.first > q->first)
        {
            ll dx = point.first - q->first;
            ll dy = point.second - p->second;
            ans += dx + dy;
            s.insert(point);
        }
    }
    printf("%lld\n", ans);
}