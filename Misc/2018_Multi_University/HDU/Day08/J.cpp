#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 17;
int a[N], vpos[N], belong[N];
vector<int> s, f[N];
bool ins[N];

int find(const vector<int>& v, int x)
{
    int l = 0, r = v.size() - 1;
    if (x >= a[v.back()]) return v.size();
    int ans = 0;
    while (l <= r)
    {
        int m = l + r >> 1;
        if (a[v[m]] > x)
            r = m - 1, ans = m;
        else
            l = m + 1;
    }
    return ans;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, m;
        s.clear();
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", a + i);
            f[i].clear();
            ins[i] = false;
        }
        vpos[1] = s.size();
        s.emplace_back(1);
        ins[1] = true;
        for (int i = 2; i <= n; i++)
        {
            if (a[i] > a[s.back()])
            {
                vpos[i] = s.size();
                s.emplace_back(i);
                ins[i] = true;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (ins[i])
                belong[i] = i;
            else
                belong[i] = belong[i - 1];
        }
        for (int i = 1; i <= n;)
        {
            if (ins[i] && !ins[i + 1])
            {
                int now = i;
                vpos[i + 1] = f[i].size();
                f[i].emplace_back(i + 1);
                int j = i + 2;
                while (!ins[j] && j <= n)
                {
                    if (a[j] > a[f[now].back()])
                    {
                        vpos[j] = f[i].size();
                        f[now].emplace_back(j);
                    }
                    ++j;
                }
                i = j;
            }
            else
                i++;
        }
        while (m--)
        {
            static int pos, val;
            scanf("%d%d", &pos, &val);
            if (ins[pos])
            {
                if (val >= a[pos])
                {
                    int tmp = find(s, val);
                    printf("%d\n", vpos[pos] + 1 + (s.size() - tmp));
                }
                else
                {
                    int flag = 0;
                    if (pos != 1)
                    {
                        if (val <= a[s[vpos[pos] - 1]])
                        {
                            val = a[s[vpos[pos] - 1]];
                            flag = 1;
                        }
                    }
                    if (f[pos].empty())
                        printf("%d\n", s.size() - flag);
                    else
                    {
                        int tmp = find(f[pos], val);
                        printf("%d\n", s.size() - flag + (f[pos].size() - tmp));
                    }
                }
            }
            else
            {
                if (val <= a[pos] || val <= a[belong[pos]])
                    printf("%d\n", s.size());
                else
                {
                    int tmp = find(s, val);
                    printf("%d\n", vpos[belong[pos]] + 2 + (s.size() - tmp));
                }
            }
        }
    }
    return 0;
}