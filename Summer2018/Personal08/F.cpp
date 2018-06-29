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

const int N = 1 << 17;
struct Trie
{
    int ch[N][26], f[N], val[N];
    int sz, rt;
    int newNode()
    {
        memset(ch[sz], -1, sizeof(ch[sz]));
        val[sz] = 0;
        return sz++;
    }
    void init() { sz = 0, rt = newNode(); }
    inline int idx(const char& c) { return c - 'a'; }
    void insert(const string& s, const int& v)
    {
        int u = rt;
        for (auto& t : s)
        {
            int c = idx(t);
            if (!~ch[u][c]) ch[u][c] = newNode();
            u = ch[u][c];
        }
        val[u] += v;
    }
    void build()
    {
        queue<int> q;
        f[rt] = rt;
        for (int c = 0; c < 26; c++)
        {
            if (~ch[rt][c])
                f[ch[rt][c]] = rt, q.push(ch[rt][c]);
            else
                ch[rt][c] = rt;
        }
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            val[u] += val[f[u]];
            for (int c = 0; c < 26; c++)
            {
                if (~ch[u][c])
                    f[ch[u][c]] = ch[f[u]][c], q.push(ch[u][c]);
                else
                    ch[u][c] = ch[f[u]][c];
            }
        }
    }

    typedef vector<ll> vec;
    typedef vector<vec> mat;

    mat floyd(mat& A, mat& B)
    {
        mat C(A.size(), vec(B[0].size()));
        for (int i = 0; i < A.size(); i++)
            for (int j = 0; j < B.size(); j++)
            {
                C[i][j] = -1e18;
                for (int k = 0; k < B[0].size(); k++)
                    C[i][j] = max(C[i][j], A[i][k] + B[k][j]);
            }
        return C;
    }

    mat Mul(mat A, ll n)
    {
        mat B = A;
        for (; n; n >>= 1, A = floyd(A, A))
            if (n & 1) B = floyd(B, A);
        return B;
    }

    void solve(ll m)
    {
        mat G(sz, vec(sz));
        for (int i = 0; i < sz; i++)
            for (int j = 0; j < sz; j++)
                G[i][j] = -1e18;
        for (int u = 0; u < sz; u++)
            for (int c = 0; c < 26; c++)
                G[u][ch[u][c]] = val[ch[u][c]];
        G = Mul(G, m - 1);
        ll ans = 0;
        for (int i = 0; i < sz; i++) ans = max(ans, G[rt][i]);
        W(ans);
    }

} ac;

void go()
{
    ac.init();
    int n;
    ll m;
    R(n, m);
    VI v(n);
    R(v);
    string buf;
    for (auto& t : v)
    {
        R(buf);
        ac.insert(buf, t);
    }
    ac.build();
    ac.solve(m);
}