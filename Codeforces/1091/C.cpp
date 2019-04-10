#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    vector<long long> ans;
    for (long long i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            long long x = i;
            ans.push_back((2 + (n - 1) / x * x) * ((n - 1) / x + 1) / 2);
            if (i == n / i) continue;
            x = n / i;
            ans.push_back((2 + (n - 1) / x * x) * ((n - 1) / x + 1) / 2);
        }
    }
    sort(ans.begin(), ans.end());
    for (auto& t : ans) cout << t << " ";
}