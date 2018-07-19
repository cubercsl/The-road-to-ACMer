#include <bits/stdc++.h>
using namespace std;
 
const int N = 10;
int G[N][N];
vector<pair<int, int>> edges;
map<pair<int, int>, int> dic;
int p[N];
 
int getid(int x, int y)
{
    if (x > y) swap(x, y);
    assert(x < y);
    if (dic[{x, y}]) return dic[{x, y}];
    return dic[{x, y}] = dic.size();
}
 
long long check()
{
    long long hash = 0;
    for (auto& e : edges)
    {
        int u = p[e.first], v = p[e.second];
        if (G[u][v])
            hash |= 1LL << getid(u, v);
        else
            return -1;
    }
    return hash;
}
 
int main()
{
    int n, a, b;
    while (~scanf("%d%d%d", &n, &a, &b))
    {
        memset(G, 0, sizeof(G));
        dic.clear();
        edges.clear();
        for (int i = 0, u, v; i < a; i++)
        {
            scanf("%d%d", &u, &v);
            --u, --v;
            edges.emplace_back(u, v);
        }
        for (int i = 0, u, v; i < b; i++)
        {
            scanf("%d%d", &u, &v);
            --u, --v;
            G[u][v] = G[v][u] = 1;
            getid(u, v);
        }
        for (int i = 0; i < n; i++) p[i] = i;
        set<long long> s;
        do
        {
            int tmp = check();
            if (~tmp) s.insert(tmp);
        } while (next_permutation(p, p + n));
        int ans = s.size();
        printf("%d\n", ans);
    }
}