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

string dfs(const string& s, int l, int r) // 左闭右开
{
    if (r - l == 1)
        return s.substr(l, 1);
    // cout << "dfs" << s.substr(l, r - l) << endl;
    if (r - l == 2 && isdigit(s[l + 1]))
    {
        char atom = s[l];
        int num = s[r - 1] - '0';
        cout << atom << num << "=" << atom;
        for (int i = 2; i <= num; i++)
            cout << "+" << atom;
        cout << endl;
        return s.substr(l, r - l);
    }
    vector<string> v;     // 记录递归结果
    int lb = -1, rb = -1; // 是否在括号内
    int cnt = 0;          // 括号层次
    for (int i = l; i < r; i++)
    {
        if (lb < 0 && i < r - 1)
        {
            if (isalpha(s[i]))
            {
                if (isdigit(s[i + 1]))
                    v.pb(dfs(s, i, i + 2));
                else
                    v.pb(s.substr(i, 1));
            }
        }
        if (i == r - 1 && isalpha(s[i]))
            v.pb(s.substr(i, 1));
        if (s[i] == '(')
            if (++cnt == 1) lb = i;
        if (s[i] == ')')
            if (--cnt == 0)
            {
                rb = i;
                v.pb(dfs(s, lb + 1, rb));
                lb = rb = -1;
            }
    }
    // cout << v.size() << endl;
    // cout <<  s.substr(l + 1, r - l - 2) <<endl;
    if(!(v.size() == 1 && s.substr(l + 1, r - l - 2) == v[0]))
    {   // 整个表达式在一个括号内
        cout << s.substr(l, r - l) << "=" << v[0];
        for (int i = 1; i < v.size(); i++) cout << "+" << v[i];
        cout << endl;
    }
    return s.substr(l, r - l);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    string s;
    while (cin >> s, s != "0")
    {
        dfs(s, 0, s.length());
        cout << endl;
    }
    return 0;
}
