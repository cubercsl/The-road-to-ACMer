#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> b(a);
    sort(b.begin(), b.end(), greater<int>());
    long long sum = 0;
    multiset<int> s;
    for (int i = 0; i < m * k; i++) sum += b[i], s.insert(b[i]);
    int cnt = 0, tot = 0;
    cout << sum << endl;
    for (int i = 0; i < n; i++)
    {
        auto it = s.find(a[i]);
        if (it == s.end()) continue;
        cnt++;
        s.erase(it);
        if (cnt == m && tot != k - 1) cout << i + 1 << ' ', cnt = 0, tot++;
    }
}