#include <bits/stdc++.h>
using namespace std;

const int N = 2000;
const int p = 47;
int a[N][N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "w", stdout);
#endif
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            a[i][j] = 0;
    for (int i = 0; i < p; i++)
        for (int j = 0; j < p; j++)
        {
            int t = j;
            for (int k = 0; k < p; k++)
            {
                int x = i * p + j;
                int y = k * p + t;
                if (x < N && y < N) a[x][y] = 1;
                (t += i) %= p;
            }
        }
    printf("2000\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%d", a[i][j]);
        puts("");
    }
}