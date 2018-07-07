#include <bits/stdc++.h>
using namespace std;

#pragma optimize("-O3")

typedef long long ll;
typedef long double ld;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

string to_string(string s) { return '"' + s + '"'; }

string to_string(const char* s) { return to_string((string)s); }

string to_string(const bool& b) { return (b ? "true" : "false"); }

template <typename A, typename B>
string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }

template <typename A>
string to_string(const A& v)
{
    bool first = true;
    string res = "{";
    for (const auto& x : v)
    {
        if (!first)
            res += ", ";
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T)
{
    cerr << " " << to_string(H);
    debug_out(T...);
}

#ifndef ONLINE_JUDGE
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__);
#else
#define debug(...) 42;
#define cerr \
    if (false) cout
#endif

template <typename T>
inline void _read(T& x)
{
    cin >> x;
}

template <typename A, typename B>
inline void _read(pair<A, B>& x)
{
    _read(x.first);
    _read(x.second);
}

template <typename T>
inline void _read(vector<T>& x)
{
    for (auto& v : x)
        _read(v);
}

void R() {}

template <typename T, typename... U>
void R(T& head, U&... tail)
{
    _read(head);
    R(tail...);
}

#define endl '\n'

template <typename T>
inline void _write(const T& x)
{
    cout << x << ' ';
}

template <typename A, typename B>
inline void _write(const pair<A, B>& x)
{
    _write(x.first);
    _write(x.second);
}

template <typename T>
inline void _write(const vector<T>& in)
{
    for (const auto& x : in)
        _write(x);
}

void W() { cout << endl; }

template <typename T, typename... U>
void W(const T& head, const U&... tail)
{
    _write(head);
    W(tail...);
}

#define my_sort_unique(c) (sort(c.begin(), c.end()), c.resize(distance(c.begin(), unique(c.begin(), c.end()))))
#define my_unique(a) a.resize(distance(a.begin(), unique(a.begin(), a.end())))
#define X first
#define Y second

void go();

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    go();
    return 0;
}

/****************************************************************************************************/

const int mod = 1e9 + 7;

#define N 10000
class bint
{
private:
    int a[N]; // 用 N 控制最大位数
    int len;  // 数字长度
public:
    // 构造函数
    bint() { len = 1, memset(a, 0, sizeof(a)); }
    // int -> bint
    bint(int n)
    {
        len = 0;
        memset(a, 0, sizeof(a));
        int d = n;
        while (n)
            d = n / 10 * 10, a[len++] = n - d, n = d / 10;
    }
    // char[] -> int
    bint(const char s[])
    {
        memset(a, 0, sizeof(a));
        len = 0;
        int l = strlen(s);
        for (int i = l - 1; ~i; i--) a[len++] = s[i];
    }
    // 拷贝构造函数
    bint(const bint& b)
    {
        memset(a, 0, sizeof(a));
        len = b.len;
        for (int i = 0; i < len; i++) a[i] = b.a[i];
    }
    // 重载运算符 bint = bint
    bint& operator=(const bint& n)
    {
        len = n.len;
        for (int i = 0; i < len; i++) a[i] = n.a[i];
        return *this;
    }
    // 重载运算符 bint + bint
    bint operator+(const bint& b) const
    {
        bint t(*this);
        int res = b.len > len ? b.len : len;
        for (int i = 0; i < res; i++)
        {
            t.a[i] += b.a[i];
            if (t.a[i] >= 10) t.a[i + 1]++, t.a[i] -= 10;
        }
        t.len = res + a[res] == 0;
        return t;
    }
    // 重载运算符 bint - bint
    bint operator-(const bint& b) const
    {
        bool f = *this > b;
        bint t1 = f ? *this : b;
        bint t2 = f ? b : *this;
        int res = t1.len, j;
        for (int i = 0; i < res; i++)
            if (t1.a[i] < t2.a[i])
            {
                j = i + 1;
                while (t1.a[j] == 0) j++;
                t1.a[j--]--;
                while (j > i) t1.a[j--] += 9;
                t1.a[i] += 10 - t1.a[i];
            }
            else
                t1.a[i] -= t2.a[i];
        t1.len = res;
        while (t1.a[len - 1] == 0 && t1.len > 1) t1.len--, res--;
        if (f) t1.a[res - 1] = 0 - t1.a[res - 1];
        return t1;
    }
    // 重载运算符 bint * bint
    bint operator*(const bint& b) const
    {
        bint t;
        int i, j, up, tmp, tmp1;
        for (i = 0; i < len; i++)
        {
            up = 0;
            for (j = 0; j < b.len; j++)
            {
                tmp = a[i] * b.a[j] + t.a[i + j] + up;
                if (tmp > 9)
                    tmp1 = tmp - tmp / 10 * 10, up = tmp / 10, t.a[i + j] = tmp1;
                else
                    up = 0, t.a[i + j] = tmp;
            }
            if (up) t.a[i + j] = up;
        }
        t.len = i + j;
        while (t.a[t.len - 1] == 0 && t.len > 1) t.len--;
        return t;
    }
    // 重载运算符 bint / int
    bint operator/(const int& b) const
    {
        bint t;
        int down = 0;
        for (int i = len - 1; ~i; i--)
            t.a[i] = (a[i] + down * 10) / b, down = a[i] + down * 10 - t.a[i] * b;
        t.len = len;
        while (t.a[t.len - 1] == 0 && t.len > 1) t.len--;
        return t;
    }
    // 重载运算符 bint ^ n (n次方快速幂, 需保证n非负)
    bint operator^(const int n) const
    {
        bint t(*this), rt(1);
        if (n == 0) return 1;
        if (n == 1) return *this;
        int m = n;
        for (; m; m >>= 1, t = t * t)
            if (m & 1) rt = rt * t;
        return rt;
    }
    // 重载运算符 bint > bint 比较大小
    bool operator>(const bint& b) const
    {
        int p;
        if (len > b.len) return 1;
        if (len == b.len)
        {
            p = len - 1;
            while (a[p] == b.a[p] && p >= 0) p--;
            return p >= 0 && a[p] > b.a[p];
        }
        return 0;
    }
    // 重载运算符 bint > int 比较大小
    bool operator>(const int& n) const { return *this > bint(n); }
    // 输出
    void out()
    {
        for (int i = len - 1; ~i; i--) printf("%d", a[i]);
        puts("");
    }
};

void go()
{
    int n;
    R(n);
    VI a(n + 1);
    for (int i = 1; i <= n; i++) R(a[i]);
    vector<VI> G(n + 1);
    for (int i = 1; i <= n; i++)
    {
        bint x = a[i];
        for (int j = i + 1; j <= n; j++)
        {
            bint y = a[j];
            bint xx = x ^ j, yy = y ^ i;
            if (yy > xx) G[i].push_back(j);
        }
    }
    debug(G);
    ll ans = 0;
    for (int s = 1; s <= n; s++)
    {
        VI dp(n + 1);
        dp[s] = 1;
        for (int i = s; i <= n; i++)
        {
            for (auto& j : G[i])
                (dp[j] += dp[i]) %= mod;
            (ans += dp[i]) %= mod;
        }
    }
    cout << ans << endl;
}