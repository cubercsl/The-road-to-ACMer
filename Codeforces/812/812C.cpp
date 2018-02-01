#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, S;
    int a[100002];
    long long cost[100002];
    cin >> n >> S;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int l = 0, r = n;
    int cnt = 0, ans = 0;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        long long sum = 0;
        for (int i = 1; i <= n; i++)
            cost[i] = a[i] + i * mid;
        sort(cost + 1, cost + 1 + n);
        for (int i = 1; i <= mid; i++)
        {
            sum += cost[i];
            if (sum > S)
                break;
        }
        if (sum <= S)
            l = mid + 1, ans = sum, cnt = mid;
        else
            r = mid - 1;
    }
    cout << cnt << " " << ans << endl;
    return 0;
}
