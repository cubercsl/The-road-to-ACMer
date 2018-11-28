#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
typedef long long ll;
struct Node
{
    int l, r;
    mutable ll val;
    Node(int l = 0, int r = 0, ll val = 0) : l(l), r(r), val(val) {}
    bool operator<(const Node& A) const
    {
        return l < A.l;
    }
};
set<Node> odt;
struct Case
{
    int l, r, cnt, cost;
    bool operator<(const Case& A) const
    {
        if (cost == A.cost) return cnt > A.cnt;
        return cost < A.cost;
    }
};
Case a[maxn];

set<Node>::iterator split(int pos)
{
    auto it = odt.lower_bound(Node(pos));
    if (it != odt.end() && it->l == pos) return it;
    --it;
    if (it->r < pos)
        return ++it;
    else
    {
        int L = it->l, R = it->r;
        ll v = it->val;
        odt.erase(it);
        odt.insert(Node(L, pos - 1, v));
        return odt.insert(Node(pos, R, v)).first;
    }
}
ll ans;
void solve(int l, int r, int cnt, int cost)
{
    auto itl = split(l);
    auto itr = split(r + 1);
    vector<Node> tmp;
    auto it = itl;
    for (; itl != itr; itl++)
    {
        if (itl->val <= cnt)
        {
            ans += 1LL * itl->val * (itl->r - itl->l + 1) * cost;
            tmp.push_back(*itl);
        }
        else
        {
            ans += 1LL * cnt * (itl->r - itl->l + 1) * cost;
            itl->val -= cnt;
        }
    }
    for (auto& v : tmp)
        odt.erase(v);
}
int main()
{
    int n, k, m;
    scanf("%d%d%d", &n, &k, &m);
    for (int i = 0; i < m; i++)
        scanf("%d%d%d%d", &a[i].l, &a[i].r, &a[i].cnt, &a[i].cost);
    sort(a, a + m);
    odt.insert(Node(0, 0, 0));
    odt.insert(Node(n+1, n+1, 0));
    odt.insert(Node(1, n, k));
    ans = 0;
    for (int i = 0; i < m; i++)
        solve(a[i].l, a[i].r, a[i].cnt, a[i].cost);
    printf("%lld\n", ans);
}