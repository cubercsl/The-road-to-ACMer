#include <bits/stdc++.h>
using namespace std;

const int N = 2005;
char s[N][N];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++) scanf("%s", s[i]);
        int r = m / 2 - 1, c = n / 2 - 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m / 2; j++)
            {
                if (s[i][j] != s[i][m - 1 - j])
                {
                    r = min(r, j);
                    break;
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n / 2; j++)
            {
                if (s[j][i] != s[n - 1 - j][i])
                {
                    c = min(c, j);
                    break;
                }
            }
        }
        printf("%d\n", r * c);
    }
}