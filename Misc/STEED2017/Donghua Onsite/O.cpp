#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long a[20004];
    int n;
    while (cin >> n)
    {
        n *= 2;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        long long sum = 0;
        for (int i = 0; i < n; i += 2)
            sum += a[i + 1] - a[i];
        cout << sum << endl;
    }
    return 0;
}
