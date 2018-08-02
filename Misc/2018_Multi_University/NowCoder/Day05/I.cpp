// ybmj
#include <bits/stdc++.h>
using namespace std;
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define lson_len (len - (len >> 1))
#define rson_len (len >> 1)
#define pb(x) push_back(x)
#define clr(a, x) memset(a, x, sizeof(a))
#define mp(x, y) make_pair(x, y)
#define my_unique(a) a.resize(distance(a.begin(), unique(a.begin(), a.end())))
#define my_sort_unique(c) (sort(c.begin(), c.end())), my_unique(c)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
const int INF = 0x3f3f3f3f;
const int NINF = 0xc0c0c0c0;
const int maxn = 1e5 + 5;
const int mod = 998244353;
struct P {
    int x, y;
    bool operator<(const P& A) const {
        if (x == A.x) return y < A.y;
        return x < A.x;
    }
};
P p[maxn];
 
int BIT[maxn];
inline int lowb(int x) { return x & (-x); }
inline int query(int l,int r){
    int ret = 0;
    for(int i=l-1;i>0;i-=lowb(i)) ret -= BIT[i];
    for(int i=r;i>0;i-=lowb(i)) ret += BIT[i];
    return ret;
}
inline void update(int x,int y,int n){
    for(int i=x;i<=n;i+=lowb(i)) BIT[i] += y;
}
 
int main() {
// /*
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    // */
    std::ios::sync_with_stdio(false);
    int n;
    while (~scanf("%d", &n)) {
        vector<int> x(n), y(n), tx(x), ty(n);
        map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &x[i], &y[i]);
            tx[i] = x[i];
            ty[i] = y[i];
        }
        my_sort_unique(x);
        my_sort_unique(y);
        for (int i = 0; i < n; i++) {
            p[i].x = lower_bound(x.begin(), x.end(), tx[i]) - x.begin() + 1;
            p[i].y = lower_bound(y.begin(), y.end(), ty[i]) - y.begin() + 1;
            cnt[p[i].y]++;
        }
        ll ans = 0;
        for (auto& v : cnt) {
            // printf("%d   %d\n",v.first , v.second);
            ans += 1LL * (n - v.second) * v.second;
        }
        ans /= 2;
        ans = (ans + n) % mod;
        // printf("ans = %lld \n ",ans );
        clr(BIT,0);
        sort(p, p + n);
        int last = 0;
        for (int i = n-1; i >= 0; i--) {
            int l = query(1,p[i].y - 1);
            int r = (n - i - 1 - query(1,p[i].y));
            // printf("%d   %d\n",l,r);        
            if(i < n-1 && p[i].x == p[i+1].x) last ++;
            else last = 0;
            ans += 1LL * l * (r - last);
            while (ans >= mod) ans -= mod;
            update(p[i].y,1,maxn - 1);
        }
        printf("%lld\n", ans);
    }
}