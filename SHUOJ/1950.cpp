#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int main()
{
    int t, n, m;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        if (n == 1)
        {
            if (m == 2)
                cout << "RL" << endl;
            else
                cout << -1 << endl;
        }
        else if (m == 1)
        {
            if (n == 2)
                cout << "DU" << endl;
            else cout << -1 << endl;
        }
        else if (m % 2 == 0)
        {
            cout << "D";
            for (int i = 0; i < m; i += 2)
            {
                if (i)
                    cout << "R";
                for (int j = 1; j < n - 1; j++)
                    cout << "D";
                cout << "R";
                for (int j = 1; j < n - 1; j++)
                    cout << "U";
            }
            cout << "U";
            for (int i = 0; i < m - 1; i++)
                cout << "L";
            cout << endl;
        }
        else if (n % 2 == 0)
        {
            cout << "R";
            for (int i = 0; i < n; i += 2)
            {
                if (i)
                    cout << "D";
                for (int j = 1; j < m - 1; j++)
                    cout << "R";
                cout << "D";
                for (int j = 1; j < m - 1; j++)
                    cout << "L";
            }
            cout << "L";
            for (int i = 0; i < n - 1; i++)
                cout << "U";
            cout << endl;
        }
        else
            cout << -1 << endl;
    }
    return 0;
}
