#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
#define X first
#define Y second

const int N = 1 << 17;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<PII> a(m);
        for (int i = 0; i < m; i++) scanf("%d%d", &a[i].X, &a[i].Y);
        for (int i = 1; i <= n; i++) a.push_back({i, i});
        sort(a.begin(), a.end());
        int L = 1, R = 1;
        priority_queue<int, vector<int>, greater<int> > q;
        for (int i = 1; i <= n; i++) q.push(i);
        vector<int> ans(n + 1);
        for (auto& t : a)
        {
            while (L < t.X) q.push(ans[L++]);
            while (R <= t.Y) ans[R++] = q.top(), q.pop();
        }
        for (int i = 1; i <= n; i++) printf("%d%c", ans[i], " \n"[i == n]);
    }
}