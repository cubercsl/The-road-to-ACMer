#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1 << 20;
ll bit[2][N];

int n;
ll query(ll* t, int x)
{
    ll ret = 0;
    for (; x; x -= x & -x) ret += t[x];
    return ret;
}

void update(ll* t, int x, int v)
{
    for (; x <= n; x += x & -x) t[x] += v;
}

int a[N], pos[N];

ll query(ll* t, int x, int y)
{
    if (x > y) swap(x, y);
    return query(t, y) - query(t, x - 1);
}

mt19937 rng(time(0));

void work()
{
    for (int i = 1; i <= n; i++) bit[0][i] = bit[1][i] = 0;
    for (int i = 1; i < n; i++)
    {
        if (query(bit[i & 1], pos[i], pos[i + 1]))
        {
            puts("No");
            return;
        }
        ll x = rng();
        update(bit[i & 1], pos[i], x);
        update(bit[i & 1], pos[i + 1], -x);
    }
    puts("Yes");
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d", a + i);
        for (int i = 1; i <= n; i++) pos[a[i]] = i;
        work();
    }
}
