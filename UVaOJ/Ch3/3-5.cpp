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

char maps[5][7];
char cmd[1001];

int main()
{
    int cases = 0;
    while (gets(maps[0]))
    {
        if (maps[0][0] == 'Z')
            break;
        for (int i = 1; i < 5; ++i)
            gets(maps[i]);
        int b_x = 0, b_y = 0;
        for (int i = 0; i < 5; ++i)
            for (int j = 0; j < 5; ++j)
                if (maps[i][j] == ' ')
                {
                    b_x = i;
                    b_y = j;
                    break;
                }
        int count = 0;
        while (~scanf("%c", &cmd[count]))
            if (cmd[count] != '0')
                count++;
            else
                break;
        cmd[count] = 0;
        getchar();

        int flag = 0, x = b_x, y = b_y;
        for (int i = 0; cmd[i]; ++i)
        {
            switch (cmd[i])
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
            }

            if (x < 0 || x > 4 || y < 0 || y > 4)
            {
                flag = 1;
                break;
            }
            else
            {
                maps[b_x][b_y] = maps[x][y];
                maps[x][y] = ' ';
                b_x = x;
                b_y = y;
            }
        }

        if (cases++)
            printf("\n");
        printf("Puzzle #%d:\n", cases);

        if (flag)
            printf("This puzzle has no final configuration.\n");
        else
        {
            for (int i = 0; i < 5; ++i)
            {
                printf("%c", maps[i][0]);
                for (int j = 1; j < 5; ++j)
                    printf(" %c", maps[i][j]);
                printf("\n");
            }
        }
    }
    return 0;
}
