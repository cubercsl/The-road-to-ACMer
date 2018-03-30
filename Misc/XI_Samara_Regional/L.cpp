#include <bits/stdc++.h>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;

vector<int> G[26];
stack<int> s;

bool push(int c)
{
    int u = s.top();
    if (u == -1)
    {
        s.push(-1);
        return false;
    }
    auto pos = upper_bound(G[c].begin(), G[c].end(), u);
    if (pos == G[c].end())
        u = -1;
    else
        u = *pos;
    s.push(u);
    return ~u;
}

bool pop()
{
    s.pop();
    return ~s.top();
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    string st, op;
    cin >> st;
    for (int i = 0; i < st.length(); i++)
        G[st[i] - 'a'].push_back(i + 1);
    s.push(0);
    int n;
    cin >> n;
    while (n--)
    {
        cin >> op;
        if (op == "push")
        {
            cin >> st;
            if (push(st[0] - 'a'))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else
        {
            if (pop())
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }

    return 0;
}
