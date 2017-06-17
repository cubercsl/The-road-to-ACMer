#include <bits/stdc++.h>
using namespace std;

int maze[102][102];
int r[102];
int c[102];
int sum;
int n, m;
int main()
{
    memset(r, 0x3f, sizeof(r));
    memset(c, 0x3f, sizeof(c));
    cin >> n >> m;
    if (n <= m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> maze[i][j];
                r[i] = min(r[i], maze[i][j]);
            }
            sum += r[i];
        }
        for (int j = 0; j < m; j++)
        {
            c[j] = maze[0][j] - r[0];
            sum += c[j];
        }
        for (int i = 1; i < n; i++)
            for (int j = 0; j < m; j++)
                if (maze[i][j] - r[i] != c[j])
                {
                    cout << -1 << endl;
                    return 0;
                }
    }
    else
    {
        for (int j = 0; j < m; j++)
        {
            for (int i = 0; i < n; i++)
            {
                cin >> maze[i][j];
                c[i] = min(c[i], maze[i][j]);
            }
            sum += c[j];
        }
        for (int i = 0; i < n; i++)
        {
            r[i] = maze[i][0] - c[0];
            sum += r[i];
        }
        for (int j = 1; j < m; j++)
            for (int i = 0; i < n; i++)
                if (maze[i][j] - c[j] != r[i])
                {
                    cout << -1 << endl;
                    return 0;
                }
    }
    cout << sum << endl;
    for (int i = 0; i < n; i++)
        while (r[i]--)
            cout << "row " << i + 1 << endl;
    for (int i = 0; i < m; i++)
        while (c[i]--)
            cout << "col " << i + 1 << endl;
    return 0;
}
