#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 17;
int a[N];
int ans[N];
int fa[N];

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
void unite(int x, int y)
{
    x = find(x), y = find(y);
    if (x != y) fa[x] = y;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%d", a + i);
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) q.push({a[i], i});
        for (int i = 0; i < n; i++) ans[i] = 0, fa[i] = i;
        while (!q.empty())
        {
            auto a = q.top();
            q.pop();
            auto b = q.top();
            q.pop();
            if (a.first == 1) continue;
            if (b.first == 1) continue;
            if (a.first != b.first)
            {
                q.push(b);
            }
            else
            {
                unite(a.second, b.second);
                b.first--;
                q.push(b);
            }
        }
        int sz = 0;
        for (int i = 0; i < n; i++)
            if (find(i) == i) ans[i] = sz++;
        for (int i = 0; i < n; i++)
            ans[i] = ans[find(i)];
        for (int i = 0; i < n; i++)
    }
}