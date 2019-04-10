#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> x(n), y(n), a(n), b(n);
    // vector<pair<int, int>> a(n), b(n);
    // for (auto& t : a) cin >> t.first >> t.second;
    // for (auto& t : b) cin >> t.first >> t.second;
    for(int i = 0; i < n; i++) cin >> x[i] >> y[i];
    for(int i = 0; i < n; i++) cin >> a[i] >> b[i];

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    // cout << a[0].first + b[n - 1].first << " " << a[0].second + b[n - 1].second << endl;
    cout << x[n - 1] + a[0] << " " << y[n - 1] + b[0] << endl;
}