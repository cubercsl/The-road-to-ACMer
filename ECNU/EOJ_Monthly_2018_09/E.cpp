#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1 << 20;
ll a[N];

bool check(int m, int n, long long k)
{
    priority_queue<ll, vector<ll>, greater<ll>> q;
    ll sum = 0;
    for (int i = 0; i < m; i++) q.push(a[i]), sum += a[i];
    if (sum >= k) return true;
    for (int i = m; i < n; i++)
    {
        q.push(a[i]);
        sum += a[i];
        sum -= q.top();
        k += q.top();
        q.pop();
        if (sum >= k) return true;
    }
    return sum >= k;
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%lld", a + i);
    int l = 1, r = n;
    int ans = -1;
    while (l <= r)
    {
        int m = l + r >> 1;
        if (check(m, n, k))
            r = m - 1, ans = m;
        else
            l = m + 1;
    }
    printf("%d\n", ans);
    return 0;
}