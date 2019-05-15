#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3+5;
int a[maxn],b[maxn];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",a+i);
    for(int i=0;i<n;i++) scanf("%d",b+i);
    int ans = max(0, b[0] - a[0]);
    for(int i=0;i<n;i++){
        if(a[i] +ans >b[i]){
            break;
        }
        if(a[i] + ans < b[i]){
            ans ++;
            break;
        }
    }
    printf("%d\n",ans);
}
