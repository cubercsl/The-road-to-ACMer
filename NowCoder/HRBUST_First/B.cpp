#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {

        int n, m, k;
        cin >> n >> m >> k;
        if (n % m == 0 || n / m < (n + k) / m)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
