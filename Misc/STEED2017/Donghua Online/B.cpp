#include <bits/stdc++.h>
using namespace std;
const int maxn = 5010;
int par[maxn], num[maxn];

void init(int n)
{
    for (int i = 1; i <= n; i++)
    {
        par[i] = i;
        num[i] = 1;
    }
}

int search(int x)
{
    if (par[x] == x)
        return x;
    return par[x] = search(par[x]);
}

void unite(int x, int y)
{
    x = search(x);
    y = search(y);
    par[x] = y;
    if (x == y)
        return;
    num[y] += num[x];
}

bool same(int x, int y)
{
    return search(x) == search(y);
}

bool judge(int n)
{
    for (int i = 1; i <= n; i++)
        if (par[i] == i && num[i] % 3)
            return false;
    return true;
}

int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        init(n);
        while (m--)
        {
            int a, b;
            cin >> a >> b;
            if (!same(a, b))
                unite(a, b);
        }
        bool ans = judge(n);
        if (ans)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
