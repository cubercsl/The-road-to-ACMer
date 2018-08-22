#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 17;
typedef long long ll;
ll f[N];

const int mod = 119 << 23 | 1;

int main()
{
    f[0] = 1, f[1] = f[2] = 0;
    for (int i = 3; i < N; i++)
    {
        f[i] = f[i - 1] * (i - 2) % mod + f[i - 2] * (i - 1) % mod;
        if (i & 1)
            f[i]++;
        else
            f[i]--;
        f[i] %= mod;
        f[i] = (f[i] + mod) % mod;
    }
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        cout << f[n] << endl;
    }
}