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
const int N = 500;
map<string, int> dic;
bool G[N][N];
int id = 0;
inline int getid(const string& s)
{
    if (dic.count(s)) return dic[s];
    return dic[s] = id++;
}

int main()
{
    ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        static string s, are, worse, than, t;
        cin >> s;
        cin >> are;
        cin >> worse;
        cin >> than;
        cin >> t;
        G[getid(s)][getid(t)] = 1;
    }
    for (int k = 0; k < id; k++)
        for (int i = 0; i < id; i++)
            for (int j = 0; j < id; j++)
                G[i][j] |= (G[i][k] & G[k][j]);
    for (int i = 0; i < m; i++)
    {
        static string s, are, worse, than, t;
        cin >> s;
        cin >> are;
        cin >> worse;
        cin >> than;
        cin >> t;
        int ss = getid(s), tt = getid(t);
        if (G[ss][tt])
            cout << "Fact\n";
        else if (G[tt][ss])
            cout << "Alternative Fact\n";
        else
            cout << "Pants on Fire\n";
    }
    return 0;
}