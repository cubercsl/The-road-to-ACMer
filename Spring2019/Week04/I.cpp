#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
char s[N][N];
char t[N][N];

int main()
{
    int n, m, k;
    while(~scanf("%d%d%d", &n, &m, &k)) {
        
        for (int i = 0; i < n; i++) scanf("%s", s[i]);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                for (int kk = 0; kk < k; kk++)
                for (int ll = 0; ll < k; ll++)
                    t[i * k + kk][j * k + ll] = s[i][j];
        }
        for (int i = 0; i < k * n; i++)
        {
            for (int j = 0; j < k * m; j++)
                printf("%c", t[i][j]);
            puts("");
        }
        
    }
}