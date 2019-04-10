#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n + 1), b;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b.push_back(a[i] - a[i - 1] - 1);
    }
    int ans = a[n] - a[1] + 1;
    sort(b.begin() + 1, b.end(), greater<int>());
    for (int i = 1; i < k; i++) ans -= b[i];
    cout << ans << endl;
}