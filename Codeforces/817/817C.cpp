#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int main()
{
    long long n, s;
    while (cin >> n >> s)
    {
        long long k = 1;
        while (k <= s) k *= 10;
        k /= 10;
        if (k == 1) k = 0;
        long long t = (s - k) / 10;
        t = t * 10 + k + 9;
        if (n - t < 0)
        {
            cout << "0" << endl;
        }
        else cout << n - t << endl;
    }
    return 0;
}
