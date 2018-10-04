#include <bits/stdc++.h>
using namespace std;

// 4096*64
// 64*4096

int a[4096][64];
int b[64][4096];
char buf[4096];
constexpr int BIT = 8;
int ans[4096][4096];

int ta[4096][64 / BIT][256];
int tb[64 / BIT][4096];

void solve(vector<int>& a, int x, int y)
{
    reverse(a.begin(), a.end());
    for (int i = 0; i < 256; i++)
        for (int j = 0; j < 8; j++)
            if (i >> j & 1) ta[x][y][i] += a[j];
}

int main()
{
    int n, p, m;
    scanf("%d%d%d", &n, &p, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < p; j++)
        {
            scanf("%s", buf);
            a[i][j] = stoi(buf, 0, 16);
        }
    }
    for (int i = 0; i < 4096; i++)
        for (int j = 0; j < 64; j += 8)
        {
            vector<int> tmp(a[i] + j, a[i] + j + 8);
            solve(tmp, i, j / 8);
        }

    for (int i = 0; i < m; i++)
    {
        scanf("%s", buf);
        for (int j = 0; buf[j]; j++) b[j][i] = buf[j] - '0';
    }
    for (int i = 0; i < 4096; i++)
        for (int j = 0; j < 64; j += 8)
        {
            int x = 0;
            for (int k = 0; k < 8; k++)
                x = x * 2 + b[j + k][i];
            tb[j / 8][i] = x;
        }
    for (int i = 0; i < 4096; i++)
        for (int j = 0; j < 8; j++)
            for (int k = 0; k < 4096; k++)
                ans[i][k] = ans[i][k] + ta[i][j][tb[j][k]];
    int ret = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            ret ^= ans[i][j];
    }
    printf("%d\n", ret);
}