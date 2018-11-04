#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define dbg(args...)                             \
    do                                           \
    {                                            \
        cout << "\033[32;1m" << #args << " -> "; \
        err(args);                               \
    } while (0)
#else
#define dbg(...)
#endif
void err()
{
    cout << "\033[39;0m" << endl;
}
template <template <typename...> class T, typename t, typename... Args>
void err(T<t> a, Args... args)
{
    for (auto x : a) cout << x << ' ';
    err(args...);
}
template <typename T, typename... Args>
void err(T a, Args... args)
{
    cout << a << ' ';
    err(args...);
}
/****************************************************************************************************/

const int N = 6000;
const int maxn = 1e7 + 5;
vector<pair<int, int>> G[maxn];
int GG[maxn];
int tx[] = {-1, -1, 1, 1};
int ty[] = {-1, 1, -1, 1};

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int main()
{
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            if (i * i + j * j < maxn)
                G[i * i + j * j].emplace_back(i, j);
    for (int i = 1; i <= N; i++)
        if (i * i < maxn) GG[i * i] = i;
    // puts("fuck");
    int T, kase = 0;
    scanf("%d", &T);
    while (T--)
    {
        map<pair<int, int>, long long> dic;
        long long lst = 0;
        int n, m;
        scanf("%d%d", &n, &m);
        printf("Case #%d:\n", ++kase);

        for (int i = 0, x, y, w; i < n; i++)
        {
            scanf("%d%d%d", &x, &y, &w);
            dic[{x, y}] = w;
        }
        for (int i = 0, op, x, y, k, w; i < m; i++)
        {
            scanf("%d%d%d", &op, &x, &y);
            x = (x + lst) % 6000 + 1;
            y = (y + lst) % 6000 + 1;
            if (op == 1)
            {
                scanf("%d", &w);
                dic[{x, y}] = w;
            }
            else if (op == 2)
            {
                dic.erase({x, y});
            }
            else if (op == 3)
            {
                scanf("%d%d", &k, &w);
                if (k == 0)
                {
                    if (dic.count({x, y})) dic[{x, y}] += w;
                    continue;
                }
                for (auto& v : G[k])
                {
                    for (int t = 0; t < 4; t++)
                    {
                        int xx = x + v.first * tx[t];
                        int yy = y + v.second * ty[t];
                        if (xx <= 0 || yy <= 0 || xx > N || yy > N) continue;
                        if (dic.count({xx, yy})) dic[{xx, yy}] += w;
                    }
                }
                if (GG[k])
                {
                    for (int t = 0; t < 4; t++)
                    {
                        int xx = x + dx[t] * GG[k];
                        int yy = y + dy[t] * GG[k];
                        if (xx <= 0 || yy <= 0 || xx > N || yy > N) continue;
                        if (dic.count({xx, yy})) dic[{xx, yy}] += w;
                    }
                }
            }
            else if (op == 4)
            {
                long long ans = 0;
                scanf("%d", &k);
                if (k == 0)
                {
                    if (dic.count({x, y})) ans += dic[{x, y}];
                    printf("%lld\n", ans);
                    lst = ans;
                    continue;
                }
                for (auto& v : G[k])
                {
                    for (int t = 0; t < 4; t++)
                    {
                        int xx = x + v.first * tx[t];
                        int yy = y + v.second * ty[t];
                        if (xx <= 0 || yy <= 0 || xx > N || yy > N) continue;
                        if (dic.count({xx, yy})) ans += dic[{xx, yy}];
                    }
                }
                if (GG[k])
                {
                    for (int t = 0; t < 4; t++)
                    {
                        int xx = x + dx[t] * GG[k];
                        int yy = y + dy[t] * GG[k];
                        if (xx <= 0 || yy <= 0 || xx > N || yy > N) continue;
                        if (dic.count({xx, yy})) ans += dic[{xx, yy}];
                    }
                }
                printf("%lld\n", ans);
                lst = ans;
            }
        }
    }
    return 0;
}