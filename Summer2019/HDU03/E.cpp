#include <bits/stdc++.h>

using i64 = long long;

const int MAXN = 1001000;

int k, n;
std::vector<std::pair<int, int>> edges[MAXN];
bool visited[MAXN];

std::pair<int, i64> dfs(int u) {

    std::pair<int, i64> result = {1, 0};
    visited[u] = true;
    for(auto&& e : edges[u]) {

        int v = e.first;
        if(visited[v]) continue;
        auto x = dfs(v);
        result.first += x.first;
        result.second += x.second;
        result.second += std::min(k, x.first) * i64(e.second);

    }
    return result;

}

int main() {

    while(~std::scanf("%d%d", &n, &k)) {

        for(int i = 0; i < n; ++i)
            visited[i] = false, edges[i] = {};
        for(int i = 0; i < n - 1; ++i) {
            
            int u, v, d;
            std::scanf("%d%d%d", &u, &v, &d);
            --u, --v;
            edges[u].push_back(std::pair<int, int>(v, d));
            edges[v].push_back(std::pair<int, int>(u, d));

        }
        i64 result = dfs(0).second;
        std::printf("%lld\n", result);

    }

}