#include <bits/stdc++.h>
using namespace std;

char s[105][105];

int main()
{
    int n;
    scanf("%d", &n);
    if (n == 2) return puts("-1"),0;
    printf("%d\n", 100);
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            s[i][j] = '.';
    if(n % 2 == 0) s[98][1] = 'o';
    for(int i=1;i<=(n-1)/2;i++){
        s[99-i][0] = 'o';
        s[99][i] = 'o';
    } 
    s[99][0] = 'o';
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            printf("%c",s[i][j]);
        }
        puts("");
    }
    
}