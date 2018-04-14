#include <bits/stdc++.h>
using namespace std;
char a[15][15], b[15][15];
char tmp[15][15];

int N;
void rotate()
{
    memcpy(tmp, a, sizeof(a));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            a[i][j] = tmp[j][N - 1 - i];
}

void filp()
{
    memcpy(tmp, a, sizeof(a));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            a[i][j] = tmp[i][N - 1 - j];
}

bool check()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (a[i][j] != b[i][j])
                return 0;
    return 1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%s", a[i]);
    for (int i = 0; i < N; i++)
        scanf("%s", b[i]);
    for (int i = 0; i < 4; i++)
    {
        rotate();
        if (check()) return puts("Yes"), 0;
    }
    filp();
    for (int i = 0; i < 4; i++)
    {
        rotate();
        if (check()) return puts("Yes"), 0;
    }
    puts("No");
    return 0;
}