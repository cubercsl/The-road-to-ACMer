#include <bits/stdc++.h>
using namespace std;

long long a[100001];
const int mod = 1e9 + 7;

int main()
{
    a[0] = 1;
    for (int i = 1; i < 100000; i++)
        a[i] = i * a[i - 1] % mod;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << a[n] << endl;
    }
    return 0;
}
