// Box, ACM/ICPC NEERC 2004, UVa1587

/*Sample Input
1345 2584
2584 683
2584 1345
683 1345
683 1345
2584 683
1234 4567
1234 4567
4567 4321
4322 4567
4321 1234
4321 1234
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    const int n = 6;
    double a[6], b[6];
    while (cin >> a[0] >> b[0])
    {
        for (int i = 1; i < n; i++)
            cin >> a[i] >> b[i];
        for (int i = 0; i < n; i++)
            if (a[i] > b[i])
                swap(a[i], b[i]);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n - i - 1; j++)
                if (a[j] > a[j + 1])
                {
                    swap(a[j], a[j + 1]);
                    swap(b[j], b[j + 1]);
                }
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4 - i - 1; j++)
                if (b[j] > b[j + 1])
                {
                    swap(a[j], a[j + 1]);
                    swap(b[j], b[j + 1]);
                }
        int flag = 0;
        /*for (int i = 0; i < n; i++)
            cout << a[i] << " " << b[i] << endl;*/
        if (a[0] == a[1] && a[2] == a[3] && a[0] == a[2])
            if (b[0] == b[1] && a[4] == a[5] && b[0] == a[4])
                if (b[2] == b[3] && b[4] == b[5] && b[2] == b[4])
                    flag = 1;
        if (flag)
            cout << "POSSIBLE" << endl;
        else
            cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}
