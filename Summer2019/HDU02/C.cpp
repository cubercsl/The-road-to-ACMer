#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int maxn = 3e5+5;
int a[maxn << 1];
struct Node{
    int val, pos;
    bool operator < (const Node &rhs) const{
        if(val == rhs.val) return pos > rhs.pos;
        return val > rhs.val;
    }
};

int main(){
    int n;
    while(~scanf("%d",&n)){
        set<Node> A;        
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            A.insert(Node{a[i]-i,i});
        }
        multiset<int> B;
        for(int i=1,x;i<=n;i++){
            scanf("%d",&x);
            B.insert(-x);
        }
        int l = 1;
        int x = n+1;
        while(B.size()){
            int r = -(*B.rbegin());
            for(int i=l;i<r;i++){
                A.erase(Node{a[i]-i,i});
            }
            l = r;
            auto it = A.begin();
            a[x] = it->val;
            A.insert(Node{a[x]-x,x});
            x++;
            B.erase(B.lower_bound(-(it->pos)));
        }
        ll ans = 0;
        for(int i=n+1;i<=2*n;i++)
            ans = (ans + a[i]) % mod;
        printf("%lld\n",ans);
    }
}