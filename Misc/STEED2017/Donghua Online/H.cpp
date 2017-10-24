#include <bits/stdc++.h>
using namespace std;

int main()
{
    int c[102];
    int n;
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
            cin >> c[i];
        sort(c, c + n);
        for (int i = 0; i < n - 1; i++)
            c[i + 1] = (c[i] + c[i + 1]) / 2;
        cout << c[n - 1] << endl;
    }
}
