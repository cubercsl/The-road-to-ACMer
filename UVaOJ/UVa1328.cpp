// Period, UVa1328

/*Sample Input
3
aaa
12
aabaabaabaab
0
*/

#include <bits/stdc++.h>
using namespace std;
#define clr(a,x) memset(a, x, sizeof(a))
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;

const int maxn  = 1e6 + 5;
int ne[maxn];
void init(string s, int n)
{
    int i = 0, j = -1;
    ne[0] = -1;
    while (i < n)
    {
        while (j != -1 && s[i] != s[j])
            j = ne[j];
        ne[++i] = ++j;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin
    string s;
    int n, kase = 0;
    while (cin >> n, n)
    {
        cin >> s;
        init(s, n);
        cout << "Test case #" << ++kase << endl;
        for (int i = 2; i <= n; i++)
            if (ne[i] && i % (i - ne[i]) == 0)
                cout << i << " " << i / (i - ne[i]) << endl;
        cout << endl;
    }
    return 0;
}
