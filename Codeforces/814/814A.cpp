#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, flag;
    int a[102];
    int b[102];
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] == 0)
            flag = i;
    }

    for (int i = 0; i < m; i++)
        cin >> b[i];
    if (m != 1)
        cout << "Yes" << endl;
    if (m == 1)
    {
        a[flag] = b[0];
        for (int i = 0; i < n - 1; i++)
            if (a[i] >= a[i + 1])
            {
                cout << "Yes" << endl;
                return 0;
            }
        cout << "No" << endl;
    }
    return 0;
}
