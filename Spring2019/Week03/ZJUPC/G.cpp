#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5+5;
int n,k;
pair<ll,ll> solve(vector<ll> &a){
    sort(a.begin(),a.end(),greater<ll>());
    ll cnt = k, x, ret = 0;
    ll y = 0;
    if(a.size()) y = a[0];
    for(auto &v:a){
        if(cnt == k){
            x = v;
        }
        cnt--;
        if(cnt == 0){
            ret += x * 2;
            cnt = k;
        }
    }
    if(cnt == k) return make_pair(ret - y, ret);
    else return make_pair(ret + x * 2 - y, ret + x * 2);
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        vector<ll> a,b;
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;i++){
            ll x;
            scanf("%lld",&x);
            if(x >= 0) a.push_back(x);
            else b.push_back(-x);
        }
        pair<ll,ll> resa = solve(a);
        pair<ll,ll> resb = solve(b);
        // printf("%lld %lld\n",resa.first,resa.second);
        // printf("%lld %lld\n",resb.first,resb.second);

        printf("%lld\n",min(resa.first + resb.second, resa.second + resb.first));
    }
}