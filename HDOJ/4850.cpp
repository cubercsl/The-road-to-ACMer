#include <bits/stdc++.h>
using namespace std;

const int N = 26;
bool vis[N][N][N][N];
int a[500005];
const int maxn = 26 * 26 * 26 * 26 + 4;

inline void init()
{
    for (int i = 4; i < maxn; i++)
        for (int j = 25; ~j ; j--)
            if (vis[a[i - 3]][a[i - 2]][a[i - 1]][j] == 0)
            {
                a[i] = j;
                vis[a[i - 3]][a[i - 2]][a[i - 1]][j] = 1;
                break;
            }
}

int main()
{
    init();
    int n;
    while (~scanf("%d", &n))
    {
        if (n < maxn)
        {
            for (int i = 1; i <= n; i++)
                putchar(a[i] + 'a');
            puts("");
        }
        else
            puts("Impossible");
    }
    return 0;
}