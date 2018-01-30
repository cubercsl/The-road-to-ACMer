#include <bits/stdc++.h>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;
const int maxn = 1e5 + 5;
//int dp[maxn];
int ans;
vector<int> G[maxn];
/*
int dfs(int u){
    int temp = 0;
    for(int i=0;i<G[u].size();i++){
        temp = max(temp,dfs(G[u][i]));
    }
    return dp[u] = temp + 1;
}
*/
int solve(int u, int dep, int fa)
{
    if (G[u].size() == 1 && G[u][0] == fa) {
        // cout << "u = " << u << endl;
        return 1;
    }
    if (dep & 1) {
        int temp = INF;
        for (int i = 0; i < G[u].size(); i++) {
            int v = G[u][i];
            if (v != fa)
                temp = min(temp, solve(v, dep + 1, u));
        }
        return temp;
    }
    else
    {
        int temp = 0;
        for (int i = 0; i < G[u].size(); i++) {
            int v = G[u][i];
            if (v != fa)
                temp += solve(v, dep + 1, u);
        }
        return temp;
    }
}
/*
void work(int u,int dep){
    if(G[u].size() == 0){
        ans++;
        return;
    }
    
    if(dep & 1){
        int temp = -1;
        int k = -1;
        for(int i=0;i<G[u].size();i++){
            if(dp[G[u][i]] > temp){
                temp = dp[G[u][i]];
                k = G[u][i];
            }
        }
        work(k,dep+1);
    }
    else{
        for(int i=0;i<G[u].size();i++){
            work(G[u][i],dep+1);
        }
    }
}
*/
int main()
{
#ifndef ONLINE_JUDGE
// freopen("1.in", "r", stdin);
// freopen("1.out", "w", stdout);
#endif
    fastin int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 0; i <= n; i++) G[i].clear();
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        //dfs(1);
        ans = 0;
        // work(1,1);
        ans = solve(1, 1, -1);
        cout << ans << '\n';
    }
    return 0;
}