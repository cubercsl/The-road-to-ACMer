#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 17;
vector<int> G[N];
vector<int> a, b;
int c[N], vis[N], in[N];
map<int, int> dic;
int rev[N];

int sz = 0;
int id(int x)
{
    if (dic.find(x) != dic.end()) return dic[x];
    rev[sz] = x;
    return dic[x] = sz++;
}

int main()
{
    int n;
    scanf("%d", &n);
    set<int> s;
    for (int i = 0, x, y; i < n; i++)
    {
        scanf("%d%d", &x, &y);
        x = id(x), y = id(y);
        if (x == y)
            a.push_back(rev[x]), b.push_back(rev[y]), vis[x] = true;
        else
            G[x].push_back(y), G[y].push_back(x);
    }
    memset(c, -1, sizeof(c));
    for (int i = 0; i < sz; i++)
    {
        if (vis[i]) continue;
        if (~c[i]) continue;
        queue<int> q;
        c[i] = 0;
        q.push(i);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (auto& v : G[u])
            {
                if (vis[v]) continue;
                if (~c[v]) continue;
                c[v] = (c[u] ^ 1);
                q.push(v);
            }
        }
    }
    for (int i = 0; i < sz; i++)
    {
        if (vis[i]) continue;
        assert(~c[i]);
        if (c[i])
            a.push_back(rev[i]);
        else
            b.push_back(rev[i]);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int x = a.size(), y = b.size();
    if (x > y || (x == y && a > b)) swap(a, b), swap(x, y);
    printf("%d %d\n", x, y);
    for (int i = 0; i < x; i++) printf("%d%c", a[i], " \n"[i == x - 1]);
    for (int i = 0; i < y; i++) printf("%d%c", b[i], " \n"[i == y - 1]);
}