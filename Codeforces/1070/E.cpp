#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define X first
#define Y second
#define PII pair<int, int>
const int maxn = 2e5 + 5;
int n, m, b[maxn];
PII a[maxn];
ll t;
bool check(int cnt)
{
    ll tmp = 0;
    int lim = cnt % m;
    lim = lim ? lim : m;
    priority_queue<int, vector<int>, greater<int>> Q;
    for (int i = 0; i < cnt; i++)
    {
        tmp += 2 * a[i].X;
        if (Q.size() < lim)
            Q.push(a[i].Y);
        else if (a[i].Y > Q.top())
        {
            Q.pop();
            Q.push(a[i].Y);
        }
    }
    while (Q.size())
    {
        int tt = Q.top();
        Q.pop();
        tmp -= a[tt].X;
    }
    return tmp <= t;
}
int judge(int d)
{
    ll tmp = t;
    int cnt = 0, mm = 0, tt = 0;
    for (int i = 0; i < n; i++)
    {
        if (b[i] <= d)
        {
            if (b[i] > tmp) break;
            cnt++, mm++, tt += b[i], tmp -= b[i];
            if (mm == m)
                tmp -= tt, mm = 0, tt = 0;
        }
    }
    return cnt;
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%lld", &n, &m, &t);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &b[i]);
            a[i].X = b[i], a[i].Y = i;
        }
        sort(a, a + n);
        int l = 1, r = n;
        int ans = 0, dd = 1;
        while (l <= r)
        {
            int mid = (r - l) / 2 + l;
            if (check(mid))
                ans = mid, dd = a[mid - 1].X, l = mid + 1;
            else
                r = mid - 1;
        }
        if (ans)
        {
            int ans1 = judge(dd), ans2 = judge(dd - 1);
            if (ans1 >= ans2)
                ans = ans1;
            else
                ans = ans2, dd -= 1;
        }
        printf("%d %d\n", ans, dd);
    }
}