#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& t : a) cin >> t;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i += 2) cout << a[i] << ' ';
    for (int i = n - 1; ~i; i--)
        if (i & 1) cout << a[i] << ' ';
}