#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
struct Node
{
    ll a, b;
    Node(ll a = 0, ll b = 0) : a(a), b(b) {}
    bool operator<(const Node& rhs) const
    {
        int sgn1 = a < b, sgn2 = rhs.a < rhs.b;
        return sgn1 < sgn2 || sgn1 == sgn2 && (a < b ? a > rhs.a : b < rhs.b);
    }
    Node& operator+=(const Node& rhs)
    {
        Node ret = *this;
        ret.a = max(a, a - b + rhs.a);
        ret.b = b + rhs.b - a - rhs.a + ret.a;
        return *this = ret;
    }
};

typedef pair<Node, int> HeapNode;
typedef __gnu_pbds::priority_queue<HeapNode> Heap;

const int N = 1 << 17;
Node a[N];
int fa[N], del[N];
vector<int> G[N];
Heap::point_iterator id[N];

void dfs(int u, int p)
{
    fa[u] = p;
    for (auto& v : G[u])
        if (v != p) dfs(v, u);
}

int find(int x) { return del[fa[x]] ? fa[x] = find(fa[x]) : fa[x]; }

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) G[i].clear(), del[i] = 0, id[i] = 0;
        for (int i = 2; i <= n; i++) scanf("%lld%lld", &a[i].a, &a[i].b);
        for (int i = 1, u, v; i < n; i++)
        {
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }

        dfs(1, 0);
        a[1] = {0, 0};
        Heap q;
        for (int i = 2; i <= n; i++) id[i] = q.push({a[i], i});

        while (!q.empty())
        {
            HeapNode t = q.top();
            q.pop();
            int x = t.second;
            del[x] = 1;
            int y = find(x);
            a[y] += a[x];
            if (y > 1)
            {
                if (id[y] != 0)
                    q.modify(id[y], {a[y], y});
                else
                    id[y] = q.push({a[y], y});
            }
        }
        printf("%lld\n", a[1].a);
    }
}