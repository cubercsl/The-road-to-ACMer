#include <bits/stdc++.h>
using namespace std;
const int maxn = 8e4+5;
char s[2][maxn];
int n,x,y;
bool ok(int a){
    int z = min(x,y);
    if(z <= a){
        return (x - z + y -z <= n - a) ;
    } else{
        return (x - a + y-a <= n-a);
    }
}
int main()
{

    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&x,&y);
        scanf("%s%s",s[0],s[1]);
        int a = 0;
        for(int i=0;i<n;i++){
            if(s[0][i] == s[1][i]){
                a++;
            }
        }
        if(ok(a)) puts("Not lying");
        else puts("Lying");

    }
}
/*
2
3 1 3
AAA
ABC
5 5 0
ABCBC
ACBCB

 */