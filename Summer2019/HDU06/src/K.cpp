#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        int sum = 0;
        int a,b,c,ab,ac,bc,abc;
        for(int i=0;i<n;i++){
            scanf("%d%d%d%d%d%d%d",&a,&b,&c,&ab,&bc,&ac,&abc);
            ab -= abc;
            bc -= abc;
            ac -= abc;
            if(ab < 0 || bc < 0 || ac < 0) continue;
            a = a - ab - ac - abc;
            b = b - ab - bc - abc;
            c = c - bc - ac - abc;
            if(a < 0 || b < 0 || c < 0)continue;
            int tmp = a + b + c + ab + bc + ac +abc;
            sum = max(sum,tmp);
        }
        printf("%d\n",sum);
    }
}