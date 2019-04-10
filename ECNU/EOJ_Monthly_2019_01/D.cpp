#include <bits/stdc++.h>
using namespace std;

char s[1 << 20];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%s", s);
        for (int i = 1; s[i]; i++)
            if (s[i - 1] == s[i])
                printf("C");
            else
                printf("D");
        puts("");
    }
}