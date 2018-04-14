#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef pair<int, int> PII;
typedef tree<PII, null_type, greater<PII>, rb_tree_tag, tree_order_statistics_node_update> rbtree;

const int N = 1 << 17;
int fa[N], cnt[N];
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {
        iota(fa, fa + n + 1, 0);
        fill(cnt, cnt + n, 1);
        rbtree T;
        for (int i = 1; i <= n; i++) T.insert({1, i});
        while(m--)
        {
            static int op, a, b;
            scanf("%d", &op);
            if (op == 0)
            {
                scanf("%d%d", &a, &b);
                a = find(a), b = find(b);
                if (a == b) continue;
                fa[b] = a;
                T.erase({cnt[a], a}), T.erase({cnt[b], b});
                cnt[a] += cnt[b];
                T.insert({cnt[a], a});
            }
            else
            {
                scanf("%d", &a);
                a--;
                printf("%d\n",T.find_by_order(a)->first);
            }
        }
    }
    return 0;
}