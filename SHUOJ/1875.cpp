#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int m;
ll a[100], ins[64];

void guess()
{
    for (int i = 0; i < m; i++)
        for (int j = 63; j >= 0; j--)
            if ((a[i] >> j) & 1)
            {
                if (!ins[j])
                {
                    ins[j] = a[i];
                    break;
                }
                else a[i] ^= ins[j];
            }
}

int main()
{
    while (cin >> m)
    {
        memset(ins, 0, sizeof(ins));
        for (int i = 0; i < m; i++)
            cin >> a[i];
        guess();
        bool flag = 0;
        for (int i = 0; i < m; i++)
            if (a[i] == 0)
            {
                flag = 1;
                break;
            }
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
