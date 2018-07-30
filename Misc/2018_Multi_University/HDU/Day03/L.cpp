#include <bits/stdc++.h>
using namespace std;

const int N = 150;
char s[N][N];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        static int a, b, c;
        memset(s, 0, sizeof(s));
        scanf("%d%d%d", &a, &b, &c);
        int R = (b + c) * 2 + 1;
        int C = (a + b) * 2 + 1;
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                s[i][j] = '.';
        for (int i = 0; i < c; i++)
            for (int j = 0; j < a; j++)
            {
                s[b * 2 + i * 2][j * 2] = '+';
                s[b * 2 + i * 2][j * 2 + 1] = '-';
                s[b * 2 + i * 2 + 1][j * 2] = '|';
            }
        // for (int i = 0; i < c; i++)
        // {
        //     s[b * 2 + i * 2][C - 1 - b * 2] = '+';
        //     s[b * 2 + i * 2 + 1][C - 1 - b * 2] = '|';
        // }
        for (int j = 0; j < a; j++)
        {
            s[R - 1][j * 2] = '+';
            s[R - 1][j * 2 + 1] = '-';
        }
        // s[R - 1][C - 1 - b * 2] = '+';

        for (int i = 0; i < b; i++)
            for (int j = 0; j < a; j++)
            {
                s[i * 2][j * 2 + (b - i) * 2] = '+';
                s[i * 2][j * 2 + (b - i) * 2 + 1] = '-';
                s[i * 2 + 1][j * 2 + (b - i) * 2 - 1] = '/';
            }
        for (int i = 0; i < c; i++)
            for (int j = 0; j < b; j++)
            {
                s[2 * (b - j + i)][2 * (a + j)] = '+';
                s[2 * (b - j + i) - 1][2 * (a + j) + 1] = '/';
                s[2 * (b - j + i) + 1][2 * (a + j)] = '|';
            }
        for (int i = 0; i < c; i++)
        {
            s[i * 2][C - 1] = '+';
            s[i * 2 + 1][C - 1] = '|';
        }
        for (int j = 0; j < b; j++)
        {
            s[2 * (b - j + c)][2 * (a + j)] = '+';
            s[2 * (b - j + c) - 1][2 * (a + j) + 1] = '/';
        }
        s[2 * c][C - 1] = '+';
        for (int i = 0; i < R; i++) puts(s[i]);
    }
}