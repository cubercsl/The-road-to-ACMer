// S-Trees, UVa712

/*Sample Input
3
x1 x2 x3
00000111
4
000
010
111
110
3
x3 x1 x2
00010011
4
000
010
111
110
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

const int maxn = 10;
string s, t, q;
int num[maxn];
int Pow[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin
    int kase = 0;
    int n, m;
    while (cin >> n, n)
    {
        q.clear();
        for (int i = 0; i < n; i++)
        {
            cin >> t;
            num[i] = t[1] - '0';
        }
        cin >> s;
        cin >> m;
        int beg = Pow[n];
        for (int i = 0; i < m; i++)
        {
            cin >> t;
            int k = 1;
            for (int j = 0; j < n; j++)
                if (t[num[j] - 1] == '1')
                    k = k << 1 | 1;
                else
                    k <<= 1;
            q.pb(s[k - beg]);
        }
        cout << "S-Tree #" << ++kase << ":" << endl;
        cout << q << endl << endl;

    }
    return 0;
}
