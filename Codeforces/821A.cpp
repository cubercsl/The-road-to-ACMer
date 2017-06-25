#include <bits/stdc++.h>
using namespace std;

int n;
int a[50][50];
bool judge (int x, int y, int num)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[x][j] + a[i][y] == num)
                return true;
    return false;
}

bool solve()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] != 1 && (!judge(i, j, a[i][j])))
                return false;
    return true;
}

int main()
{
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> a[i][j];
        if (solve())
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
