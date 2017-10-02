// Seek the Name, Seek the Fame, POJ2752

/*Sample Input
ababcababababcabab
aaaaa
*/

#include <cstring>
#include <iostream>
#include <string>
#include <vector>
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

const int maxn = 1 << 20;
int ne[maxn];
void getfail(const string& s)
{
    int i, j, m = s.length();
    j = ne[0] = -1;
    i = 0;
    while (i < m)
    {
        while (j != -1 && s[i] != s[j])
            j = ne[j];
        ne[++i] = ++j;
    }
}

void print(int len)
{
    if (!ne[len]) return;
    print(ne[len]);
    cout << ne[len] << " ";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    string s;
    while (cin >> s)
    {
        getfail(s);
        print(s.length());
        cout << s.length() << endl;
    }
    return 0;
}
