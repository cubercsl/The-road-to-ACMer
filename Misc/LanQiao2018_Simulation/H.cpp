#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1 << 17;
int pre[N], suf[N];
ll pre_sum[N], suf_sum[N];
int d[N];
int main()
{
    int n;
    while (cin >> n)
    {
        vector<int> v(n);
        for (auto& t : v) cin >> t;
        sort(v.begin(), v.end());
        for (int i = 1; i < n; i++) d[i] = v[i] - v[i - 1];
        ll ans = INT_MAX;
        for (int i = 1; i < n; i++) pre[i] = __gcd(pre[i - 1], d[i]), pre_sum[i] = pre_sum[i - 1] + d[i];
        for (int i = n - 1; i; i--) suf[i] = __gcd(suf[i + 1], d[i]), suf_sum[i] = suf_sum[i + 1] + d[i];
        for (int i = 1; i < n; i++)
        {
            int gg = __gcd(pre[i - 1], suf[i + 1]);
            ll tmp = pre_sum[i - 1] / gg - (i - 1) + suf_sum[i + 1] / gg - (n - i - 1);
            ans = min(ans, tmp);
        }
        // ans = min(ans, suf_sum[1] / suf[1] - (n - 2));
        // ans = min(ans, pre_sum[n - 1] / pre[n - 1] - (n - 2));
        cout << ans << endl;
    }
}