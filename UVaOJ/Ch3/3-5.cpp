// Puzzle, ACM/ICPC World Finals 1993, UVa227

/*Sample Input
TRGSJ
XDOKI
M VLN
WPABE
UQHCF
ARRBBL0
ABCDE
FGHIJ
KLMNO
PQRS
TUVWX
AAA
LLLL0
ABCDE
FGHIJ
KLMNO
PQRS
TUVWX
AAAAABBRRRLL0
Z
*/

#include <bits/stdc++.h>
using namespace std;

string maps[5];
char cmd;

int main()
{
    int cases = 0;
    while (getline(cin, maps[0]))
    {
        if (maps[0][0] == 'Z')
            break;
        for (int i = 1; i < 5; i++)
            getline(cin, maps[i]);
        int b_x = 0, b_y = 0;
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++)
                if (maps[i][j] == ' ')
                {
                    b_x = i;
                    b_y = j;
                    break;
                }
        int flag = 0, x = b_x, y = b_y;
        while (cin >> cmd, cmd != '0')
        {
            if (flag)
                continue;
            {
                switch (cmd)
                {
                case 'A':
                    x = b_x - 1;
                    y = b_y;
                    break;
                case 'B':
                    x = b_x + 1;
                    y = b_y;
                    break;
                case 'L':
                    x = b_x;
                    y = b_y - 1;
                    break;
                case 'R':
                    x = b_x;
                    y = b_y + 1;
                    break;
                case '\n':
                    break;
                default:
                    flag = 1;
                }
                if (x < 0 || x > 4 || y < 0 || y > 4)
                    flag = 1;
                else
                {
                    maps[b_x][b_y] = maps[x][y];
                    maps[x][y] = ' ';
                    b_x = x;
                    b_y = y;
                }
            }
        }

        if (cases++)
            cout << endl;
        cout << "Puzzle #" << cases << ":" << endl;

        if (flag)
            cout << "This puzzle has no final configuration." << endl;
        else
        {
            for (int i = 0; i < 5; i++)
            {
                cout << maps[i][0];
                for (int j = 1; j < 5; j++)
                    cout << " " << maps[i][j];
                cout << endl;
            }
        }
        getchar();
    }
    return 0;
}
