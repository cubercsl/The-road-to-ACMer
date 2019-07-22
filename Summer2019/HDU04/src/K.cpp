#include <bits/stdc++.h>
using namespace std;

const int N = 100;
char s[N][N];
map<int, int> maps;
int p[1000];

void init()
{
    for (int i = 0; i < 7; i++) p[i] = (1 << i);
    int x = p[0] + p[1] + p[2] + p[4] + p[5] + p[6];
    maps[x] = 0;
    x = p[2] + p[5];
    maps[x] = 1;
    x = p[0] + p[2] + p[3] + p[4] + p[6];
    maps[x] = 2;
    x = p[0] + p[2] + p[3] + p[5] + p[6];
    maps[x] = 3;
    x = p[1] + p[2] + p[3] + p[5];
    maps[x] = 4;
    x = p[0] + p[1] + p[3] + p[5] + p[6];
    maps[x] = 5;
    x = p[0] + p[1] + p[3] + p[5] + p[6] + p[4];
    maps[x] = 6;
    x = p[0] + p[2] + p[5];
    maps[x] = 7;
    x = p[0] + p[1] + p[2] + p[3] + p[4] + p[5] + p[6];
    maps[x] = 8;
    x = x - p[4];
    maps[x] = 9;
}
int solve(int n)
{

    int m = n + 3;
    vector<int> cnt(7);
    for (int i = n; i <= m; i++) cnt[0] += s[0][i] == 'X', cnt[3] += s[3][i] == 'X', cnt[6] += s[6][i] == 'X';
    for (int i = 1; i <= 2; i++) cnt[1] += s[i][n] == 'X', cnt[2] += s[i][m] == 'X';
    for (int i = 4; i <= 5; i++) cnt[4] += s[i][n] == 'X', cnt[5] += s[i][m] == 'X';
    int x = 0;
    for (int i = 0; i < 7; i++)
    {
        if (cnt[i]) x |= 1 << i;
    }
    // printf("%d\n",x);
    return maps[x];
}
int main()
{
    int T;
    scanf("%d", &T);
    init();
    while (T--)
    {
        for (int i = 0; i < 7; i++) scanf("%s", s[i]);
        int a = solve(0);
        int b = solve(5);
        int c = solve(12);
        int d = solve(17);
        printf("%d%d:%d%d\n", a, b, c, d);
    }
}