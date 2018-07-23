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
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
const int INF = 0x3f3f3f3f;
const int NINF = 0xc0c0c0c0;
struct P {
    string line;
    ll l, r;
};
pii work(string &line) {
    int l = 0, r = 0;
    for (auto &c : line) {
        if (c == '(')
            l++;
        else if (l > 0)
            l--;
    }
    for (int i = line.size() - 1; i >= 0; i--) {
        if (line[i] == ')')
            r++;
        else if (r > 0)
            r--;
    }
    return mp(l, r);
}
int main() {
    // /*
    #ifndef ONLINE_JUDGE
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    #endif
    // */
    std::ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<P> vec(n);
        for (int i = 0; i < n; i++) {
            cin >> vec[i].line;
            pii foo = work(vec[i].line);
            vec[i].l = foo.first;
            vec[i].r = foo.second;
        }
        sort(vec.begin(), vec.end(), [](const P &A, const P &B) {
            // if(A.l - A.r == B.l - B.r) return A.l > B.l;
            // else return A.l - A.r > B.l - B.r;
            if(min(A.l,B.r) == min(A.r,B.l)) return A.l > B.l;
            return min(A.l,B.r) > min(A.r,B.l);
            /*
            if(A.l - B.r == B.l - A.r)    A.r + B.l < A.l + B.r;
            return A.l - B.r > B.l - A.r ;
            // return A.r + B.l + abs(A.l - B.r) < B.r + A.l + abs(B.l - A.r);
            */
        });
        ll ans = 0, l = 0;
        for(int i=0;i<n;i++){
            // cout << vec[i].l << ' ' << vec[i].r << endl;
            ans += vec[i].line.size() - vec[i].l - vec[i].r;
            ans += min(l,vec[i].r) * 2;
            l = max(0LL, l - vec[i].r);
            l += vec[i].l;
        }
        cout << ans << endl;
    }
}