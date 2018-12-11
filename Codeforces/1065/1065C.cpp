#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& t : a) cin >> t;
    sort(a.begin(), a.end(), greater<int>());
    int ans = 0;
    ll cost = 0, cnt = 1;
    int lst = a[0];
    for (int i = 1; i < n; i++)
    {
        while (cost + cnt * (lst - a[i]) >= k)
        {
            ans++;
            lst -= (k - cost) / cnt;
            cost = 0;
        }
        cost += cnt * (lst - a[i]);
        cnt++;
        lst = a[i];
    }
    if (cost) ans++;
    cout << ans << endl;
}