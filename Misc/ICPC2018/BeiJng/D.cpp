#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1 << 21;
int a[N], b[N];
ll d[N];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        ll c;
        scanf("%d%lld", &n, &c);
        for (int i = 0; i < n; i++) scanf("%d", a + i);
        for (int i = 0; i < n; i++) scanf("%d", b + i);
        for (int i = 0; i < n; i++) a[n + i] = a[i];
        for (int i = 0; i < n; i++) b[n + i] = b[i];
        for (int i = 0; i < n * 2; i++) d[i] = a[i] - b[i];
        for (int i = 1; i < n * 2; i++) d[i] += d[i - 1];
        deque<pair<ll, int>> q;
        int k = n;
        int ans = -1;
        for (int i = 0, j = 0; i < n; i++)
        {
            while (j < i + k)
            {
                while (!q.empty() && q.back().first > d[j]) q.pop_back();
                q.push_back({d[j], j}), j++;
            }
            while (q.front().second < i) q.pop_front();
            if (c + q.front().first >= 0)
            {
                ans = i + 1;
                break;
            }
            c -= a[i] - b[i];
        }
        printf("%d\n", ans);
    }
}