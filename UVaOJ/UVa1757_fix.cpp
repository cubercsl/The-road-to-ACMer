// Secret Chamber at Mount Rushmore, ACM/ICPC World Final 2017, UVa1757

/*Sample Input
9 5
c t
i r
k p
o c
r o
t e
t f
u h
w p
we we
can the
work people
it of
out the
3 3
a c
b a
a b
aaa abc
abc aaa
acm bcm
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

const int maxn = 26;
bool G[maxn][maxn];

void init()
{
    for (int i = 0; i < maxn; i++)
        for (int j = 0; j < maxn; j++)
            G[i][j] = i == j;
}

void add_edge(int u, int v)
{
    G[u][v] = 1;
}

void floyd()
{
    for (int k = 0; k < maxn; k++)
        for (int i = 0; i < maxn; i++)
            for (int j = 0; j < maxn; j++)
                G[i][j] |= (G[i][k] & G[k][j]);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m;
    while (cin >> n >> m)
    {
        init();
        while (n--)
        {
            char u, v;
            cin >> u >> v;
            add_edge(u - 'a', v - 'a');
        }
        floyd();
        while (m--)
        {
            string a, b;
            cin >> a >> b;
            if (a.length() != b.length())
                cout << "no" << endl;
            else
            {
                bool no = 0;
                for (int i = 0; i < a.length(); i++)
                    if (!G[a[i] - 'a'][b[i] - 'a'])
                    {
                        no = 1;
                        break;
                    }
                if (no)
                    cout << "no" << endl;
                else
                    cout << "yes" << endl;
            }
        }
    }
    return 0;
}
