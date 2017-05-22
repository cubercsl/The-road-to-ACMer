// Digit Counting, ACM/ICPC Danang 2007, UVa1225

/*Sample Input
2
3
13
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int f[10000][10];
    for (int i = 1; i < 10000; i++)
    {
        for (int j = 0; j < 10; j++)
            f[i][j] = f[i - 1][j];
        int left = i;
        while (left)
        {
            f[i][left % 10]++;
            left /= 10;
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < 9; i++)
            cout << f[n][i] << " ";
        cout << f[n][9] << endl;
    }
    return 0;
}
