#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Node
{
    int w;
    int d;
    Node(int w, int d) : w(w), d(d) {}
    bool operator<(const Node& rhs) const
    {
        if (w == rhs.w) return d < rhs.d;
        return w > rhs.w;
    }
};
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        ll ans = 0, cnt = 0;
        priority_queue<Node> q;
        for (int i = 0, x; i < n; i++)
        {
            scanf("%d", &x);
            if (!q.empty() && q.top().w < x)
            {
                ans -= q.top().w;
                ans += x;
                if (q.top().d == 0) cnt += 2;
                q.pop();
                q.push({x, 1});
                q.push({x, 0});
            }
            else
                q.push({x, 0});
        }
        printf("%lld %lld\n", ans, cnt);
    }
}