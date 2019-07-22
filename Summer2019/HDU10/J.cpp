#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
struct Node1{
    int s,t;
    bool operator < (const Node1 &rhs) const {
        if(t == rhs.t) return s > rhs.s;
        return t > rhs.t;
    }
};
typedef pair<int,int> pii;
pii a[maxn];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        priority_queue<pii,vector<pii>, greater<pii>> pq;
        for(int i=0;i<n;i++){
            scanf("%d%d",&a[i].first,&a[i].second);
            pq.push(a[i]);
        }
        int cnt = 0;
        long long ans = 0;
        priority_queue<int> exits;
        priority_queue<int,vector<int>, greater<int>> use;
        while(pq.size()){
            pii now = pq.top();
            pq.pop();
            while(!use.empty()){
                if(use.top() <= now.first) {
                    // ans -= use.top().t - use.top().s;
                    exits.push(use.top());
                    use.pop();
                } else break;
            }
            if(exits.empty()){
                use.push(now.second);
                ans += now.second - now.first;
                cnt++;
            } else{
                ans += now.second - exits.top();
                use.push(now.second);
                exits.pop();
            }
        }
        
        printf("%d %lld\n",cnt,ans);
    }
}