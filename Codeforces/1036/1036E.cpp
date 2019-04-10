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
typedef double db;
const db eps = 1e-6;

#define zero(x) ((fabs(x) < eps ? 1 : 0))
#define sgn(x) (fabs(x) < eps ? 0 : ((x) < 0 ? -1 : 1))

struct point
{
    db x, y;
    point(db a = 0, db b = 0) { x = a, y = b; }
    point operator-(const point& b) const { return point(x - b.x, y - b.y); }
    point operator+(const point& b) const { return point(x + b.x, y + b.y); }
    // 两点是否重合
    bool operator==(point& b) { return zero(x - b.x) && zero(y - b.y); }
    // 点积(以原点为基准)
    db operator*(const point& b) const { return x * b.x + y * b.y; }
    // 叉积(以原点为基准)
    db operator^(const point& b) const { return x * b.y - y * b.x; }
    // 绕P点逆时针旋转a弧度后的点
    point rotate(point b, db a)
    {
        db dx, dy;
        (*this - b).split(dx, dy);
        db tx = dx * cos(a) - dy * sin(a);
        db ty = dx * sin(a) + dy * cos(a);
        return point(tx, ty) + b;
    }
    // 点坐标分别赋值到a和b
    void split(db& a, db& b) { a = x, b = y; }
};
struct line
{
    point s, e;
    line() {}
    line(point ss, point ee) { s = ss, e = ee; }
};

bool segxseg(line l1, line l2)
{
    return max(l1.s.x, l1.e.x) >= min(l2.s.x, l2.e.x) && max(l2.s.x, l2.e.x) >= min(l1.s.x, l1.e.x) && max(l1.s.y, l1.e.y) >= min(l2.s.y, l2.e.y) && max(l2.s.y, l2.e.y) >= min(l1.s.y, l1.e.y) && sgn((l2.s - l1.e) ^ (l1.s - l1.e)) * sgn((l2.e - l1.e) ^ (l1.s - l1.e)) <= 0 && sgn((l1.s - l2.e) ^ (l2.s - l2.e)) * sgn((l1.e - l2.e) ^ (l2.s - l2.e)) <= 0;
}

// <0, *> 表示重合; <1, *> 表示平行; <2, P> 表示交点是P;
pair<int, point> spoint(line l1, line l2)
{
    point res = l1.s;
    if (sgn((l1.s - l1.e) ^ (l2.s - l2.e)) == 0)
        return make_pair(sgn((l1.s - l2.e) ^ (l2.s - l2.e)) != 0, res);
    db t = ((l1.s - l2.s) ^ (l2.s - l2.e)) / ((l1.s - l1.e) ^ (l2.s - l2.e));
    res.x += (l1.e.x - l1.s.x) * t;
    res.y += (l1.e.y - l1.s.y) * t;
    return make_pair(2, res);
}

int OnSegment(line l) { return __gcd(abs((int)(l.s.x - l.e.x)), abs((int)(l.s.y - l.e.y))) + 1; }

inline bool isint(db x) { return zero(round(x) - x); }

void go()
{
    map<int, int> dic;
    int n;
    R(n);
    for (int i = 2; i <= n; i++) dic[(i * (i - 1) / 2)] = i - 1;
    point a, b;
    vector<line> lines;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        R(a.x, a.y, b.x, b.y);
        lines.emplace_back(a, b);
        ans += OnSegment(lines.back());
    }
    map<pair<int, int>, int> cnt;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
        {
            if (!segxseg(lines[i], lines[j])) continue;
            auto res = spoint(lines[i], lines[j]);
            assert(res.first == 2);
            point p = res.second;
            if (isint(p.x) && isint(p.y))
            {
                int x = round(p.x), y = round(p.y);
                cerr << x << " " << y << endl;
                cnt[{x, y}]++;
            }
        }
    for (auto& t : cnt)
    {
        assert(dic.count(t.second));
        ans -= dic[t.second];
    }
    W(ans);
}
