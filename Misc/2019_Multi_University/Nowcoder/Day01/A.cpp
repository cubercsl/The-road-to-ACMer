#include <bits/stdc++.h>
using namespace std;

const int maxn = 1 << 17;
int lson[maxn], rson[maxn], fa[maxn];
void build(const vector<int>& a, int n)
{
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        int last = -1;
        while (!s.empty() && a[i] < a[s.top()]) last = s.top(), s.pop();
        if (!s.empty()) rson[s.top()] = i, fa[i] = s.top();
        lson[i] = last;
        if (~last) fa[last] = i;
        s.push(i);
    }
}

void dfs1(int rt, vector<int>& path)
{
    if (!~rt) return;
    path.push_back(rt);
    dfs1(lson[rt], path);
    dfs1(rson[rt], path);
}

void dfs2(int rt, vector<int>& path)
{
    if (!~rt) return;
    dfs2(lson[rt], path);
    path.push_back(rt);
    dfs2(rson[rt], path);
}
bool check(int m, const vector<int>& a,
           const vector<int>& b)
{
    int rt;
    
    for (int i = 0; i < m; i++) fa[i] = -1, lson[i] = rson[i] = -1;
    build(a, m);
    for (int i = 0; i < m; i++)
        if (fa[i] == -1) rt = i;
    vector<int> x1, y1;
    dfs1(rt, x1);
    dfs2(rt, y1);
    
    for (int i = 0; i < m; i++) fa[i] = -1, lson[i] = rson[i] = -1;
    build(b, m);
    for (int i = 0; i < m; i++)
        if (fa[i] == -1) rt = i;
    vector<int> x2, y2;
    dfs1(rt, x2);
    dfs2(rt, y2);

    // for (auto& t : x1) cerr << t <<' ';
    // cerr << endl;
    // for (auto& t : y1) cerr << t <<' ';
    // cerr << endl;

    // for (auto& t : x2) cerr << t <<' ';
    // cerr << endl;
    // for (auto& t : y2) cerr << t <<' ';
    // cerr << endl;

    if (x1 == x2 && y1 == y2) return true;
    return false;
}

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        for (int i = 0; i < n; i++) scanf("%d", &b[i]);
        // check(3, a, b);
        int l = 1, r = n, ans = 0;
        while (l <= r)
        {
            int m = l + r >> 1;
            if (check(m, a, b))
                ans = m, l = m + 1;
            else
                r = m - 1;
        }
        printf("%d\n", ans);
    }
}