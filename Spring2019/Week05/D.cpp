#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
vector<int> G[maxn];
using pii = pair<int,int>;
int n;
using t3 = tuple<int,int,int>;
int par[maxn];
int find(int x){return x == par[x] ? x : par[x] = find(par[x]);}
bool same(int u,int v){
    return find(u) == find(v);
}
void unite(int u,int v){
    u = find(u);
    v = find(v);
    if(u == v) return ;
    par[u] = v;
}
int bfs(int a,int b){
    for(int i=0;i<n;i++) par[i] = i;
    queue<t3> q;
    q.push(make_tuple(a,b,0));
    if(G[a][2] != G[b][2]) return 0;
    unite(a,b);
    while(!q.empty()){
        t3 U = q.front();
        q.pop();
        a = get<0>(U);
        b = get<1>(U);
        int t = get<2>(U);
        for(int i=0;i<2;i++){
            int na = G[a][i];
            int nb = G[b][i];
            if(same(na,nb) == false){
                unite(na,nb);
                q.push(make_tuple(na,nb,t+1));
                if(G[na][2] != G[nb][2]) return t + 1;
            }
        }
    }
    return -1;
}
int main(){
    int a,b;
    scanf("%d%d%d",&n,&a,&b);
    for(int i=0,x,y,z;i<n;i++){
        scanf("%d%d%d",&x,&y,&z);
        G[i].push_back(x);
        G[i].push_back(y);
        G[i].push_back(z);
    }
    int ans = bfs(a,b);
    if(ans == -1) puts("indistinguishable");
    else printf("%d\n",ans);
}