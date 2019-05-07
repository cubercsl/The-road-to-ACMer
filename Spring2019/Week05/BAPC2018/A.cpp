#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1e5+5;
ll a[maxn];
ll n, x;
int main() {
    scanf("%lld%lld",&n,&x);
    for(int i=0;i<n;i++) scanf("%lld",a+i);
    sort(a,a+n);
    int ans = -1;
    for(int i=1;i<n;i++){
        if(a[i] + a[i-1] > x){
            ans = i;
            break;
        }
    }
    if(ans == -1) ans = n;
    printf("%d\n",ans);

}