#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

const int N = 1 << 17;
ull f[N];

ull pow(ull a, ull b, int c)
{
    ull t = 1;
    for (; b; b >>= 1, (a *= a) %= c)
        if (b & 1) (t *= a) %= c;
    return t;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        ull a, b, c;
        cin >> a >> b >> c;
        f[0] = 0, f[1] = 1;
        for (int i = 2;; i++)
        {
            f[i] = (f[i - 1] + f[i - 2]) % c;
            if (f[i - 1] == 0 && f[i] == 1)
            {
                c = i - 1;
                break;
            }
        }
        cout << f[pow(a % c, b, c)] << endl;
    }
    return 0;
}