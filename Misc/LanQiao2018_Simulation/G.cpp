#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        if (n > m) swap(n, m);
        if (n == 1)
            cout << m << endl;
        else if (n == 2 && m == 2)
            cout << 4 << endl;
        else
            cout << (n * m + 1) / 2 << endl;
    }
}