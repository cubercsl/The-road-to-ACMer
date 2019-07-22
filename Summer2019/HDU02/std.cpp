#include<bits/stdc++.h>
#define LL long long
#define LD long double
#define ull unsigned long long
#define fi first
#define se second
#define mk make_pair
#define PLL pair<LL, LL>
#define PLI pair<LL, int>
#define PII pair<int, int>
#define SZ(x) ((int)x.size())
#define ALL(x) (x).begin(), (x).end()
#define fio ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

const int N = 2e5 + 7;
const int inf = 0x3f3f3f3f;
const LL INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-8;
const double PI = acos(-1);

template<class T, class S> inline void add(T& a, S b) {a += b; if(a >= mod) a -= mod;}
template<class T, class S> inline void sub(T& a, S b) {a -= b; if(a < 0) a += mod;}
template<class T, class S> inline bool chkmax(T& a, S b) {return a < b ? a = b, true : false;}
template<class T, class S> inline bool chkmin(T& a, S b) {return a > b ? a = b, true : false;}

int r[N], sa[N], _t[N], _t2[N], c[N], rk[N], lcp[N], san;

void buildSa(int *r, int n, int m) {
    int i, j = 0, k = 0, *x = _t, *y = _t2;
    for(i = 0; i < m; i++) c[i] = 0;
    for(i = 0; i < n; i++) c[x[i] = r[i]]++;
    for(i = 1; i < m; i++) c[i] += c[i - 1];
    for(i = n - 1; i >= 0; i--) sa[--c[x[i]]] = i;
    for(int k = 1; k <= n; k <<= 1) {
        int p = 0;
        for(i = n - k; i < n; i++) y[p++] = i;
        for(i = 0; i < n; i++) if(sa[i] >= k) y[p++] = sa[i] - k;
        for(i = 0; i < m; i++) c[i] = 0;
        for(i = 0; i < n; i++) c[x[y[i]]]++;
        for(i = 1; i < m; i++) c[i] += c[i - 1];
        for(i = n - 1; i >= 0; i--) sa[--c[x[y[i]]]] = y[i];
        swap(x, y);
        p = 1; x[sa[0]] = 0;
        for(int i = 1; i < n; i++) {
            if(y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + k] == y[sa[i] + k])
                x[sa[i]] = p - 1;
            else x[sa[i]] = p++;
        }
        if(p >= n) break;
        m = p;
     }
     for(i = 1; i < n; i++) rk[sa[i]] = i;
     for(i = 0; i < n - 1; i++) {
        if(k) k--;
        j = sa[rk[i] - 1];
        while(r[i + k] == r[j + k]) k++;
        lcp[rk[i]] = k;
     }
}

struct bit_seg {
    int Rt[N], ls[N * 50], rs[N * 50], sum[N * 50], tot, n, maxval;
    void init(int _n, int _maxval) {
        n = _n; maxval = _maxval;
        for(int i = 0; i <= tot; i++)
            sum[i] = ls[i] = rs[i] = 0;
        for(int i = 0; i <= n; i++) Rt[i] = 0;
        tot = 0;
    }
    void update(int& o, int pos, int v, int l, int r) {
        if(!o) o = ++tot;
        sum[o] += v;
        if(l == r)return ;
        int m = l + r >> 1;
        if(pos <= m) update(ls[o], pos, v, l, m);
        else update(rs[o], pos, v, m + 1, r);
    }
    int query(int o, int L, int R, int l, int r) {
        if(L > R || l > r || !o) return 0;
        if(R < l || r < L) return 0;
        if(L <= l && r <= R) return sum[o];
        int m = l + r >> 1;
        return query(ls[o] , L , R , l , m) + query(rs[o], L, R, m + 1, r);
    }
    int bitquery(int L, int R, int a, int b) {
        int ans = 0;
        for(int i = R; i; i -= i & -i) ans += query(Rt[i], a, b, 0, maxval);
        for(int i = L - 1; i; i -= i & -i) ans -= query(Rt[i], a, b, 0, maxval);
        return ans;
    }
    void bitupdate(int i,int pos,int v) {
        for( ; i <= n; i += i & -i) update(Rt[i], pos, v, 0, maxval);
    }
} S;


int Log[N];

struct ST {
    int dp[N][20], ty;
    void build(int n, int b[], int _ty) {
        ty = _ty;
        for(int i = 1; i <= n; i++) dp[i][0] = ty * b[i];
        for(int j = 1; j <= Log[n]; j++)
            for(int i = 1; i + (1 << j) - 1 <= n; i++)
                dp[i][j] = max(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
    }
    int query(int x, int y) {
        int k = Log[y - x + 1];
        return ty * max(dp[x][k], dp[y - (1 << k) + 1][k]);
    }
} rmq;

bool is[N];
char s[N], t[N];
int f[N], q;

int main() {
    for(int i = -(Log[0]=-1); i < N; i++)
        Log[i] = Log[i - 1] + ((i & (i - 1)) == 0);
    int T; scanf("%d", &T);
    while(T--) {
        san = 0;
        scanf("%s%s", s, t);
        int lens = strlen(s), lent = strlen(t);
        reverse(s, s + lens);
        reverse(t, t + lent);
        for(int i = 0; i < lens; i++) scanf("%d", &f[i]);
        reverse(f, f + lens);
        for(int i = 0; i < lens; i++) {
            is[san] = true;
            r[san++] = s[i];
        }
        is[san] = false; r[san++] = '$';
        for(int i = 0; i < lent; i++) {
            is[san] = false;
            r[san++] = t[i];
        }
        is[san] = false; r[san] = 0;
        S.init(san, lens - 1);
        buildSa(r, san + 1, 256);
        rmq.build(san, lcp, -1);
        for(int i = 1; i <= san; i++)
            if(is[sa[i]]) S.bitupdate(i, sa[i], f[sa[i]]);
        scanf("%d", &q);
        int a = 0, b = 0, c = 0, d = 0, add = 0, ans = 0, len = 0;
        int low = 0, high = 0, mid, L = 0, R = 0;
        while(q--) {
            int op; scanf("%d", &op);
            if(op == 1) {
                scanf("%d%d", &a, &b);
                a ^= ans; b ^= ans;
                a = lens - a - 1;
                if(a >= lens) {
                    return 0;
                }
                add = b - f[a];
                f[a] = b;
                S.bitupdate(rk[a], a, add);
            } else {
                scanf("%d%d%d%d", &c, &d, &a, &b);
                a ^= ans; b ^= ans; c ^= ans; d ^= ans;
                a = lens - a - 1;
                b = lens - b - 1;
                c = lent - c - 1 + lens + 1;
                d = lent - d - 1 + lens + 1;
                swap(a, b); swap(c, d);
                len = d - c + 1;
                low = 1, high = rk[c] - 1, L = rk[c], R = rk[c];
                while(low <= high) {
                    mid = low + high >> 1;
                    if(rmq.query(mid + 1, rk[c]) >= len) high = mid - 1, L = mid;
                    else low = mid + 1;
                }
                low = rk[c] + 1, high = san;
                while(low <= high) {
                    mid = low + high >> 1;
                    if(rmq.query(rk[c] + 1, mid) >= len) low = mid + 1, R = mid;
                    else high = mid - 1;
                }
                b = b - len + 1;
                if(a > b) ans = 0;
                else ans = S.bitquery(L, R, a, b);
                printf("%d\n", ans);
            }
        }
    }
    return 0;
}

/*
*/