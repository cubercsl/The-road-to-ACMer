#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
struct Node{
    int x,id,t;
    bool operator < (const Node &rhs) const {
        return x < rhs.x;
    }
}a[maxn];
int ans[maxn];

void solve(int n){
    int p;
    set<int> fk;
    bool flag = false;
    for(p=0;p<n;p++){
        int x = a[p].x;
        a[p].t = 0;
        while(true){
            auto it = fk.lower_bound(x);
            if(it == fk.end() || *it != x) {
                fk.insert(x);
                break;
            } else {
                fk.erase(it);
                x--;
            }
        }
        if(*fk.begin() == 1){
            flag = true;
            break;
        }
    }
    if(!flag){
        printf("NO\n");
        return ;
    }
    flag = false;
    fk.clear();
    for(p = p + 1; p < n; p++){
        int x = a[p].x;
        while(true){
            auto it = fk.lower_bound(x);
            if(it == fk.end() || *it != x) {
                fk.insert(x);
                break;
            } else {
                fk.erase(it);
                x--;
            }
        }
        if(*fk.begin() == 1){
            flag = true;
            break;
        }
    }
    printf("%s\n",flag ? "YES" : "NO");
    if(!flag) return ;
    for(int i=0;i<n;i++) ans[a[i].id] = a[i].t;
    for(int i=0;i<n;i++) printf("%d",ans[i]);
    puts("");
}
int main(){
    int T,kase = 1;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++) {
            scanf("%d",&a[i].x);
            a[i].id = i;
            a[i].t = 1;
        }
        sort(a,a+n);
        printf("Case %d: ",kase++);
        solve(n);
    }
}