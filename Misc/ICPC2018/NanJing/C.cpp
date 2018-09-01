#include <bits/stdc++.h>
using namespace std;

const int N = 200;
int cnt[N][15];

int main()
{
    int T, kase = 0;
    scanf("%d", &T);
    while (T--)
    {
        queue<int> q;
        int n, m;
        memset(cnt, 0, sizeof(cnt));
        scanf("%d%d", &n, &m);
        for (int i = 0, x; i < m; i++)
        {
            scanf("%d", &x);
            q.push(x);
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 5; j++)
            {
                int x = q.front();
                q.pop();
                cnt[i][x]++;
                if (q.empty()) break;
            }
        pair<int, int> now = {-1, -1};
        for (int i = 0;; i++)
        {
            if (i == n) i = 0;
            if (now.second == i)
            {
                bool flag = true;
                for (int j = i;; j++)
                {
                    if (j == n) j = 0;
                    if (!flag && j == i) break;
                    if (q.empty()) break;
                    int x = q.front();
                    q.pop();
                    cnt[j][x]++;
                    flag = false;
                }
                now.first = -1;
            }
            if (!~now.first)
            {
                for (int j = 3; j <= 13; j++)
                {
                    if (cnt[i][j])
                    {
                        now.first = j;
                        cnt[i][j]--;
                        break;
                    }
                }
                if (!~now.first)
                {
                    if (cnt[i][1])
                    {
                        now.first = 1;
                        cnt[i][1]--;
                    }
                    else
                    {
                        now.first = 2;
                        cnt[i][2]--;
                    }
                }
                now.second = i;
            }
            else
            {
                int pre = i - 1, nxt;
                if (pre == -1) pre = n - 1;
                if (now.first == 2) continue;
                if (now.first == 13)
                    nxt = 1;
                else
                    nxt = now.first + 1;
                if (cnt[i][nxt])
                {
                    cnt[i][nxt]--;
                    now = {nxt, i};
                }
                else if (cnt[i][2])
                {
                    cnt[i][2]--;
                    now = {2, i};
                }
            }
            int sum = 0;
            for (int j = 1; j <= 13; j++) sum += cnt[i][j];
            if (sum == 0) break;
        }
        printf("Case #%d:\n", ++kase);
        for (int i = 0; i < n; i++)
        {
            int ans = 0;
            for (int j = 1; j <= 13; j++) ans += cnt[i][j] * j;
            if (ans == 0)
                puts("Winner");
            else
                printf("%d\n", ans);
        }
    }
}