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

const int N = 1 << 9;
int is[N][N], has[N][N];

map<string, int> dic;
int sz;
int getid(const string& s)
{
    if (dic.find(s) == dic.end()) return dic[s] = sz++;
    return dic[s];
}

string ans[] = {"false", "true"};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    string s, t, isa;
    memset(is, 0x3f, sizeof(is));
    memset(has, 0x3f, sizeof(has));
    for (int i = 0; i < N; i++) is[i][i] = 0, has[i][i] = 0;
    for (int i = 0, x, y; i < n; i++)
    {
        cin >> s >> isa >> t;
        x = getid(s), y = getid(t);
        if (isa == "is-a")
            is[x][y] = 0, has[x][y] = min(has[x][y], 0);
        else
            has[x][y] = -1;
    }
    for (int k = 0; k < sz; k++)
        for (int i = 0; i < sz; i++)
            for (int j = 0; j < sz; j++)
                is[i][j] = min(is[i][j], is[i][k] + is[k][j]);

    for (int k = 0; k < sz; k++)
        for (int i = 0; i < sz; i++)
            for (int j = 0; j < sz; j++)
                has[i][j] = max(-1, min(has[i][j], has[i][k] + has[k][j]));

    for (int i = 0, x, y; i < m; i++)
    {
        cin >> s >> isa >> t;
        x = getid(s), y = getid(t);
        cout << "Query " << i + 1 << ": ";
        if (isa == "has-a")
            cout << ans[has[x][y] < 0] << endl;
        else
            cout << ans[is[x][y] == 0] << endl;
    }
    return 0;
}