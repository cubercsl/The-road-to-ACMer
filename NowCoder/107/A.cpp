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

map<string, string> M;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    M.insert({"zero", "ling"});
    M.insert({"one", "yi"});
    M.insert({"two", "er"});
    M.insert({"three", "san"});
    M.insert({"four", "si"});
    M.insert({"five", "wu"});
    M.insert({"six", "liu"});
    M.insert({"seven", "qi"});
    M.insert({"eight", "ba"});
    M.insert({"nine", "jiu"});
    M.insert({"ten", "shi"});
    int T;
    string s;
    cin >> T;
    while(T--)
    {
        cin >> s;
        cout << M[s] << endl;
    }
    return 0;
}