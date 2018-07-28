#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
typedef long long ll;
struct Node
{
    ll sum, id;
    Node(ll sum = 0, ll id = 0) : sum(sum), id(id){};
    bool operator<(const Node& rhs) const
    {
        return sum > rhs.sum;
    }
};

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        map<int, int> cnt;
        for (int i = 1, x; i <= n; i++)
        {
            scanf("%d", &x);
            cnt[x]++;
        }
        ll ans = -1;
        vector<Node> d;
        for (auto& t : cnt) d.emplace_back(t.second, t.first);
        sort(d.begin(), d.end());
        int p = 0;
        ll tmp = 0;
        for (int i = 0; i < d.size(); i++)
        {
            while (p < d.size() && d[p].sum >= d[i].sum) tmp += d[p].sum, p++;
            ll now = tmp - (d[i].sum - 1) * p - 1;
            if (now <= m) ans = max(ans, d[i].id);
        }
        printf("%lld\n", ans);
    }
}