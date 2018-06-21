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

bool isleap(int year) { return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0); }

int zeller(int y, int m, int d)
{
    if (m <= 2) y--, m += 12;
    int c = y / 100;
    y %= 100;
    int w = ((c >> 2) - (c << 1) + y + (y >> 2) + (13 * (m + 1) / 5) + d - 1) % 7;
    if (w < 0) w += 7;
    return w % 7;
}

vector<string> dic = {
    "",
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"};

void go()
{
    vector<int> day = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<string> dic_d = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    int y, m, d;
    while (cin >> m >> d >> y, m + d + y)
    {
        day[2] = 28;
        if (isleap(y)) day[2]++;
        if (m > 12 || d > day[m])
        {
            cout << m << "/" << d << "/" << y << " is an invalid date." << endl;
            continue;
        }
        if (y > 1752 || y == 1752 && m > 9 || y == 1752 && m == 9 && d > 13)
            cout << dic[m] << " " << d << ", " << y << " is a " << dic_d[zeller(y, m, d)] << endl;
        else if (y == 1752 && m == 9 && d > 2 && d < 14)
            cout << m << "/" << d << "/" << y << " is an invalid date." << endl;
        else
            cout << dic[m] << " " << d << ", " << y << " is a " << dic_d[(zeller(y, m, d) + 11) % 7] << endl;
    }
}