#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
struct Node{
    int d,t;
    bool operator<(const Node &A) const {
        return d < A.d;
    }
}a[maxn];
int main()
{
    int T,kase = 1;
    scanf("%d",&T);
    while(T--){
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++){
            scanf("%d",&a[i].d);
        }
        for(int i=0;i<n;i++){
            scanf("%d",&a[i].t);
        }
        sort(a,a+n);
        int ans = 0;
        for(int i=0;i<n;i++){
            if(m >= a[i].t){
                m -= a[i].t;
                ans++;
            }
            else break;
        }
        printf("Case %d: %d\n",kase++, ans);
    }
}
