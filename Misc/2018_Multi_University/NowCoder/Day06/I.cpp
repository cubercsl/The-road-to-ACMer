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

const int INF = 0x3f3f3f3f;

struct Node
{
    int x, y;
    Node() {}
    Node(int l, int r) : x(l), y(r) {}
    bool operator<(const Node& rhs) const
    {
        return x > rhs.x || x == rhs.x && y < rhs.y;
    }
    bool operator!=(const Node& rhs) const
    {
        return x != rhs.x || y != rhs.y;
    }
};

const int N = 1 << 18;
const int mod = 119 << 23 | 1;
set<Node> s[N];
PII a[N];
int ans[N], ne[N], pe[N];

void go()
{
    int T, kase = 0;
    R(T);
    while (T--)
    {
        int n, m;
        R(n, m);
        unordered_map<int, int> id;
        VI xx;
        for (int i = 1; i <= n; i++)
        {
            R(a[i].first, a[i].second);
            xx.push_back(a[i].first);
            ans[i] = 0;
            ne[i] = i + 1;
            pe[i] = i - 1;
        }
        my_sort_unique(xx);
        for (int i = 0; i < xx.size(); i++) id[xx[i]] = i + 1;
        int tot = xx.size();
        for (int i = 1; i <= tot; i++) s[i].clear();
        for (int i = 1; i <= n; i++) s[id[a[i].first]].insert({a[i].second, i});
        ll pre = 0;
        cout << "Case #" << ++kase << ":\n";
        for (int t = 1, x; t <= m; t++)
        {
            R(x);
            x ^= pre;
            int ret = 0;
            ll now = 1;
            for (int i = 1; i <= tot; i = ne[i])
            {
                if (xx[i - 1] > x) break;
                Node tmp = {-INF, -INF};
                for (auto& it : s[i])
                {
                    if (tmp != Node(-INF, -INF)) s[i].erase(tmp);
                    if (it.x < x) break;
                    ret++;
                    ans[it.y] = t;
                    now = now * it.y % mod;
                    tmp = it;
                }
                if (tmp != Node(-INF, -INF)) s[i].erase(tmp);
                if (s[i].size() == 0)
                {
                    ne[pe[i]] = ne[i];
                    pe[ne[i]] = pe[i];
                }
            }
            if (now == 1 && ans[1] != t) now = 0;
            pre = now;
            cout << ret << endl;
        }
        for (int i = 1; i <= n; i++)
        {
            cout << ans[i];
            if (i == n)
                cout << endl;
            else
                cout << " ";
        }
    }
}