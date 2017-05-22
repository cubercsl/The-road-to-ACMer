#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    int x, n;
    cin >> x >> n;
    for (int i = 2; i <= n; i++)
        if (x > i)
            cout << (i / (gcd(x, i))) << endl;
        else
            cout << (i / (gcd(i, x))) << endl;
    return 0;
}
