#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int N = 1 << 20;

int main()
{
    vector<int> inv(N, 1);
    for (int i = 2; i < N; i++) inv[i] = 1LL * (mod - mod / i) * inv[mod % i] % mod;
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        vector<int> a(n);
        for (auto& t : a) scanf("%d", &t);
        vector<int> lson(n, -1), rson(n, -1), fa(n, -1);
        stack<int> s;
        for (int i = 0; i < n; i++)
        {
            int last = -1;
            while (!s.empty() && a[i] > a[s.top()]) last = s.top(), s.pop();
            if (!s.empty()) rson[s.top()] = i, fa[i] = s.top();
            lson[i] = last;
            if (~last) fa[last] = i;
            s.push(i);
        }

        vector<int> sz(n, 1);
        int res = inv[2];
        function<void(int)> dfs = [&](int u) {
            if (~lson[u]) dfs(lson[u]), sz[u] += sz[lson[u]];
            if (~rson[u]) dfs(rson[u]), sz[u] += sz[rson[u]];
            res = 1LL * res * inv[sz[u]] % mod;
        };

        int rt;
        for (int i = 0; i < n; i++)
            if (!~fa[i]) rt = i;
        dfs(rt);
        int ans = 1LL * n * res % mod;
        printf("%d\n", ans);
    }
}