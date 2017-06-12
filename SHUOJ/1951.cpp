#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

struct apple
{
    int p, a;
} ap[1002];

bool cmp(apple a, apple b)
{
    return a.p < b.p;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, st = 0;
        cin >> n >> k;
        int t = n;
        for (int i = 0; i < n; i++)
            cin >> ap[i].p >> ap[i].a;
        sort(ap, ap + n, cmp);
        int ans = ap[n - 1].p;
        int re = k;
        for (int i = n - 1; i >= 0; i--)
        {
            if (ap[i].a > re)
                ans += ap[i].p, ap[i++].a -= re, re = k;
            else
                re -= ap[i].a;
        }
        cout << ans * 2 << endl;
    }
    return 0;
}
