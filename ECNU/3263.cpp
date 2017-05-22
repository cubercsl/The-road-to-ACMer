#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

bool road[1002];
struct region
{
    int l, r, t;
} re[1002];

bool cmp(region a, region b)
{
    return a.r < b.r;
}

int ok(int l, int r, int t)
{
    int cnt = 0;
    for (int i = l - 1; i < r; i++)
    {
        if (road[i])
            cnt++;
    }
    return max(t - cnt, 0);
} // 查询区间是否满足条件,返回还需几个

void add(int r, int cnt)
{
    int i = 1;
    while (cnt)
    {
        if (!road[r - i])
        {
            road[r - i] = 1;
            cnt--;
        }
        i++;
    }
} // 在区间内添加路灯

int main()
{
    int kase = 0;
    int t, n, m, k;
    cin >> t;
    while (t--)
    {
        int cnt = 0;
        memset(road, 0, sizeof(road));
        cin >> n >> m >> k;
        while (k--)
        {
            int i;
            cin >> i;
            road[i - 1] = 1;
        } // 记录已经有路灯的位置

        for (int i = 0; i < m; i++)
            cin >> re[i].l >> re[i].r >> re[i].t;
        sort(re, re + m, cmp); // 按右端点排序

        for (int i = 0; i < m; i++)
        {
            if (re[i].r - re[i].l + 1 < re[i].t)
            {
                cnt = -1;
                break;
            } //约束条件大于区间长度则无解
            int temp = ok(re[i].l, re[i].r, re[i].t);
            cnt += temp;
            if (temp)
                add(re[i].r, temp);
        }
        cout << "Case " << ++kase << ": " << cnt << endl;
    }
    return 0;
}
