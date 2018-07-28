//ybmj
#include<bits/stdc++.h>
using namespace std;
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define lson_len (len - (len >> 1))
#define rson_len (len >> 1)
#define pb(x) push_back(x)
#define clr(a, x) memset(a, x, sizeof(a))
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
const int INF = 0x3f3f3f3f;
const int NINF = 0xc0c0c0c0;
const int maxn = 1e7+7;
bool vis[maxn];
int prime[maxn], phi[maxn],pre[maxn];
void init() {                   // 线性筛预处理欧拉函数
    clr(vis, 0);
    phi[1] = 1;
    int tot = 0;
    for (int i = 2; i < maxn; i++) {
        if (!vis[i]) {
            prime[tot++] = i;
            phi[i] = i - 1;
        }
        for (int k = 0; k < tot && 1LL * i * prime[k] < maxn; k++) {
            vis[i * prime[k]] = 1;
            if (i % prime[k] == 0) {
                phi[i * prime[k]] = phi[i] * prime[k];
                break;
            }
            phi[i * prime[k]] = phi[i] * (prime[k] - 1);
        }
    }
    for(int i=0;i<tot;i++){
        pre[prime[i]]++;
    }
    for(int i=1;i<maxn;i++){
        pre[i] += pre[i-1];
        // cout << pre[i] << endl;
    }
}
 
int main(){
    // /*
    #ifndef ONLINE_JUDGE
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    #endif
    // */
    std::ios::sync_with_stdio(false);
    init();
    int n;
    while(cin >> n){
        ll ans = 0;
        for(int i=1;i<=n;i++){
            ll foo = pre[n / i];
            ans += foo * (foo - 1);
        }
        cout << ans << endl;
    }
}