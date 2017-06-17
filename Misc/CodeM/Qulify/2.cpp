#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int a[1 << 20];
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int flag = a[0];
        sort(a, a + n);
        int le = upper_bound(a, a + n, flag) - a - 1;
        int mo = n - le - 1;
        int rnd = 0;
        while (le)
        {
            if (mo % 2)
                le--, mo++;
            mo /= 2;
            le = (le + 1) / 2 - 1;
            rnd++;
        }
        cout << rnd << endl;
    }
    return 0;
}
