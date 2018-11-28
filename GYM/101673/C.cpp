#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define dbg(args...)                             \
    do                                           \
    {                                            \
        cout << "\033[32;1m" << #args << " -> "; \
        err(args);                               \
    } while (0)
#else
#define dbg(...)
#endif
void err()
{
    cout << "\033[39;0m" << endl;
}
template <template <typename...> class T, typename t, typename... Args>
void err(T<t> a, Args... args)
{
    for (auto x : a) cout << x << ' ';
    err(args...);
}
template <typename T, typename... Args>
void err(T a, Args... args)
{
    cout << a << ' ';
    err(args...);
}
/****************************************************************************************************/

void rotate(string& s)
{
    int sum = 0;
    for (auto& t : s) sum += t - 'A';
    sum %= 26;
    for (auto& t : s)
    {
        t -= 'A';
        (t += sum) %= 26;
        t += 'A';
    }
}

void merge(string& a, const string& b)
{
    assert(a.length() == b.length());
    for (int i = 0; i < a.length(); i++)
    {
        char& t = a[i];
        int x = b[i] - 'A';
        t -= 'A';
        (t += x) %= 26;
        t += 'A';
    }
}

int main()
{
    string s;
    cin >> s;
    int n = s.length();
    n >>= 1;
    string a = s.substr(0, n);
    string b = s.substr(n, n);
    rotate(a), rotate(b);
    dbg(a);
    merge(a, b);
    cout << a << endl;
    return 0;
}