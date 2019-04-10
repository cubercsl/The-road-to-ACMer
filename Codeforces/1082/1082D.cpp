#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 9;
int a[N];

int vis[N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (a[i] == 1) cnt++;
    if (cnt <= 2)
    {
        int s = 0, t = 0;
        for (int i = 1; i <= n; i++)
            if (a[i] == 1)
            {
                if (!s)
                    s = i;
                else
                    t = i;
            }
        if (s == 0) s = 1;
        if (t == 0) t = n;
        priority_queue<int, vector<int>, greater<int>> q;
        for (int i = 1; i <= n; i++)
            if (i != s && i != t) q.push(i);
        printf("YES %d\n", n - 1);
        if (q.empty())
        {
            printf("1\n");
            puts("1 2");
            return 0;
        }
        vector<pair<int, int>> ans;
        ans.emplace_back(s, q.top());
        while (q.size() > 1)
        {
            int x = q.top();
            q.pop();
            ans.emplace_back(x, q.top());
        }
        ans.emplace_back(q.top(), t);
        q.pop();
        printf("%d\n", static_cast<int>(ans.size()));
        for (auto& t : ans) printf("%d %d\n", t.first, t.second);
    }
    else
    {
        int s = 0, t = 0;
        for (int i = 1; i <= n; i++)
            if (a[i] == 1)
            {
                if (!s)
                    s = i;
                else
                    t = i;
            }
        priority_queue<int, vector<int>, greater<int>> q;
        for (int i = 1; i <= n; i++)
            if (i != s && i != t)
            {
                if (a[i] > 1)
                    q.push(i);
                else
                    vis[i] = true;
            }
        vector<pair<int, int>> ans;
        int d = q.size() + 1;
        if (q.empty())
            ans.emplace_back(s, t);
        else
        {
            ans.emplace_back(s, q.top());
            while (q.size() > 1)
            {
                int x = q.top();
                q.pop();
                ans.emplace_back(x, q.top());
            }
            ans.emplace_back(q.top(), t);
            q.pop();
        }
        queue<int> qq;
        for (int i = 1; i <= n; i++)
            if (vis[i])
                qq.push(i);
            else if (i != s && i != t)
            {
                a[i] -= 2;
                if (a[i]) q.push(i);
            }
        while (!qq.empty())
        {
            int x = qq.front();
            qq.pop();
            if (q.empty())
            {
                puts("NO");
                return 0;
            }
            ans.emplace_back(x, q.top());
            a[q.top()]--;
            if (a[q.top()] == 0) q.pop();
        }
        printf("YES %d\n", d);
        printf("%d\n", static_cast<int>(ans.size()));
        for (auto& t : ans) printf("%d %d\n", t.first, t.second);
    }
}