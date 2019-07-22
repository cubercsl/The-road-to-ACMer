#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int a[maxn],b[maxn],c[maxn];
typedef long long ll;

ll solve1(int n,int m){
    vector<int> vec;
    for(int i=0;i<m;i++)
        if(c[i] == 0) vec.push_back(b[i]);
    sort(vec.begin(),vec.end());
    ll ret = 0;
    for(int i=0;i<vec.size() && i < n;i++){
        if(a[i] >= vec[i]) ret += a[i] - vec[i];
        else break;
    }
    return ret;
}

ll solve2(int n,int m){
    vector<int> vec[2];
    multiset<int> mon;
    for(int i=0;i<m;i++) vec[c[i]].push_back(b[i]);
    for(int i=0;i<n;i++) mon.insert(a[i]);
    for(auto &v:vec[1]){
        auto it = mon.lower_bound(v);
        if(it == mon.end()) return 0;
        mon.erase(it);
    } 
    ll ret = 0;
    for(auto &v:vec[0]){
        auto it = mon.lower_bound(v);
        if(it == mon.end()) return 0;
        ret += *it - v;
        mon.erase(it);
    }
    while(mon.size()){
        ret += *mon.begin();
        mon.erase(mon.begin());
    }
    return ret;
}

int main(){
    int T,kase = 1;
    scanf("%d",&T);
    while(T--){
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++) scanf("%d",a+i);
        for(int i=0;i<m;i++) scanf("%d",b+i);
        for(int i=0;i<m;i++) scanf("%d",c+i);
        sort(a,a+n,[&](int a,int b){return a > b;});    
        ll ans = max(solve1(n,m), solve2(n,m));
        printf("Case %d: %lld\n",kase++,ans);
    }
}