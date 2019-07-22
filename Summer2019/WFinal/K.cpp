#include <bits/stdc++.h>
using namespace std;

string s[] = {"1113",
              "2133",
              "2243",
              "2444"};
int main()
{
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {

        if (n % 4 || m % 4)
        {
            puts("no response");
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                    printf("%c", s[i % 4][j % 4]);
                printf("\n");
            }
        }
    }
}