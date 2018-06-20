#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 17;
vector<int> G[N];

inline int query(int l, int r, int x) { return upper_bound(G[x].begin(), G[x].end(), r) - lower_bound(G[x].begin(), G[x].end(), l); }

inline bool solve(int l, int r, int d)
{
    for (int i = 2; i * i <= d; i++)
        if (d % i == 0)
        {
            int cnt = 0;
            while (d % i == 0) cnt++, d /= i;
            if (cnt > query(l, r, i)) return false;
        }
    if (d > 1)
        if (query(l, r, d) < 1) return false;
    return true;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        for (int i = 0; i < N; i++) G[i].clear();
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1, x; i <= n; i++)
        {
            scanf("%d", &x);
            for (int j = 2; j * j <= x; j++)
                while (x % j == 0) x /= j, G[j].push_back(i);
            if (x > 1) G[x].push_back(i);
        }
        while (m--)
        {
            static int l, r, d;
            scanf("%d%d%d", &l, &r, &d);
            puts(solve(l, r, d) ? "Yes" : "No");
        }
    }
    return 0;
}