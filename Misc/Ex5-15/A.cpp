#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    int kase = 0;
    cin >> t;
    while (t--)
    {
        char a[20][20];
        bool m[20][20];
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
                m[i][j] = a[i][j] - '0';
            }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++)
                    if (m[i][k] && m[k][j])
                        m[i][j] = 1;
        cout << "Case " << ++kase << ":" << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << m[i][j];
            cout << endl;
        }
    }
    return 0;
}
