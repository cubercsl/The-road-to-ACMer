#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef pair<int, int> PII;
typedef tree<PII, null_type, greater<PII>, rb_tree_tag, tree_order_statistics_node_update> rb_tree;
const int INF = 0x3f3f3f3f;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    while (T--)
    {
        rb_tree s;
        int n, m, k, t = 0;
        scanf("%d%d", &n, &m);
        while (n--)
        {
            scanf("%d", &k);
            s.insert(make_pair(k, t++));
        }
        char op[10];
        while (m--)
        {
            scanf("%s%d", op, &k);
            if (op[0] == 'i')
                s.insert(make_pair(k, t++));
            else if (op[0] == 'd')
                s.erase(s.lower_bound(make_pair(k, INF)));
            else
                printf("%d\n", s.find_by_order(k - 1)->first);
        }
    }
    return 0;
}