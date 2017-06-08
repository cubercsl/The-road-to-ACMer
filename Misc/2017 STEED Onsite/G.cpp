#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, n;
    while (cin >> m >> n)
    {
        if ((m + n) % 2)
            if (m > n + 1 || n > m + 1)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}
