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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    string s, t;
    while (getline(cin, s))
    {
        string tmp = "";
        for (auto c : s)
        {
            if (c == ' ' || c == '\t') continue;
            if (c >= 'a' && c <= 'z') c = c - 'a' + 'A';
            tmp.pb(c);
        }
        // cout << tmp.substr(0, 8) << endl;
        if (tmp == "<DOCUMENT>")
        {
            for (;;)
            {
                getline(cin, s);
                string tmp = "";
                for (auto c : s)
                {
                    if (c == ' ' || c == '\t') continue;
                    if (c >= 'a' && c <= 'z') c = c - 'a' + 'A';
                    tmp.pb(c);
                }
                if (tmp == "</DOCUMENT>") break;
                if (tmp.substr(0, 8) == "<MESSAGE")
                {
                    for (;;)
                    {
                        getline(cin, s);
                        string tmp = "";
                        for (auto c : s)
                        {
                            if (c == ' ' || c == '\t') continue;
                            if (c >= 'a' && c <= 'z') c = c - 'a' + 'A';
                            tmp.pb(c);
                        }
                        int flag = 0;
                        // cout << tmp.substr(0, 8) << endl;

                        if (tmp.substr(0, 9) == "</MESSAGE")
                            break;
                        else
                        {
                            for (auto c : s)
                            {
                                if (flag == 0 && (c == ' ' || c == '\t')) continue;
                                flag = 1;
                                cout << c;
                            }
                            cout << endl;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
