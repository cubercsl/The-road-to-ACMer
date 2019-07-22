#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5+5;
struct func{
    int a,b,c,x;

    ll get(ll y) const{
       return  a * y * y + b * y + c;
    }
    ll diff() const{
        return get(x+1) - get(x);
    }
    bool operator < (const func &rhs) const{
        return diff() > rhs.diff();
    }
}f[maxn];

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    priority_queue<func> pq;
    ll ans = 0;
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&f[i].a,&f[i].b,&f[i].c);
        f[i].x = 0;
        ans += f[i].diff() + f[i].c;
        f[i].x++;
        m--;
        pq.push(f[i]);
    }
    while(m--){
        func now = pq.top();
        pq.pop();
        ans += now.diff();
        now.x++;
        pq.push(now);
    }
    printf("%lld\n",ans);

}