#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int num[10005];
int a[1 << 20];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            num[a[i]]++;
        }
        ll ans1 = 1e9;
        ll ans2 = 1;
        int pre = -1;
        tuple<int, int, int, int> ans;
        sort(a, a + n);
        for (int j = 0; j < n; j++)
        {
            if (j > 0 && a[j] == a[j - 1]) continue;
            int i = a[j];
            if (num[i] >= 4)
            {
                ll t1 = 4LL * i * i;
                ll t2 = 1LL * i * i;
                if (ans1 * t2 > t1 * ans2)
                {
                    ans1 = t1, ans2 = t2;
                    ans = {i, i, i, i};
                }
            }
            else if (num[i] >= 2 && pre != -1)
            {
                ll t1 = 1LL * (pre + i) * (pre + i);
                ll t2 = 1LL * pre * i;
                if (ans1 * t2 > t1 * ans2)
                {
                    ans1 = t1, ans2 = t2;
                    ans = {pre, pre, i, i};
                }
            }
            if (num[i] >= 2) pre = i;
        }
        for (int i = 0; i < n; i++) num[a[i]]--;
        int u, v, w, x;
        tie(u, v, w, x) = ans;
        printf("%d %d %d %d\n", u, v, w, x);
    }
}