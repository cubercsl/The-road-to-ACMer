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
    map<char, PII> dic;
    dic['A'] = {0, 1},
    dic['B'] = {0, 1},
    dic['C'] = {0, 1},
    dic['D'] = {0, 2},
    dic['E'] = {0, 2},
    dic['F'] = {0, 2},
    dic['G'] = {1, 0},
    dic['H'] = {1, 0},
    dic['I'] = {1, 0},
    dic['J'] = {1, 1},
    dic['K'] = {1, 1},
    dic['L'] = {1, 1},
    dic['M'] = {1, 2},
    dic['N'] = {1, 2},
    dic['O'] = {1, 2},
    dic['P'] = {2, 0},
    dic['Q'] = {2, 0},
    dic['R'] = {2, 0},
    dic['S'] = {2, 0},
    dic['T'] = {2, 1},
    dic['U'] = {2, 1},
    dic['V'] = {2, 1},
    dic['W'] = {2, 2},
    dic['X'] = {2, 2},
    dic['Y'] = {2, 2},
    dic['Z'] = {2, 2};
    int T;
    cin >> T;
    while (T--)
    {
        string s;
        cin >> s;
        int x = 0, y = 0;
        int ans = 0;
        for (auto& t : s)
        {
            ans += abs(dic[t].X - x) + abs(dic[t].Y - y);
            x = dic[t].X, y = dic[t].Y;
        }
        cout << ans << endl;
    }
    return 0;
}
