// Parity game, POJ1733

/*Sample Input
10
5
1 2 even
3 4 odd
5 6 even
1 6 even
7 10 odd
*/

#include <iostream>
#include <algorithm>
#include <vector>
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

const int maxn = 5005;
PII node[maxn];
int par[maxn << 1];
bool val[maxn];

void init(int n)
{
    for (int i = 0; i <= n; i++)
        par[i] = i, val[i] = 0;
}

int find(int x)
{
    if (par[x] == x) return x;
    int tmp = find(par[x]);
    val[x] ^= val[par[x]];
    return par[x] = tmp;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1.in", "r", stdin);
    //freopen("1.out", "w", stdout);
#endif
    fastin
    int n, m;
    VI v;
    char parity[maxn][10];
    while (cin >> n >> m)
    {
        v.clear();
        for (int i = 0; i < m; i++)
        {
            cin >> node[i].X >> node[i].Y >> parity[i];
            node[i].X--;
            v.pb(node[i].X);
            v.pb(node[i].Y);
        }
        sort(v.begin(), v.end());
        int size = unique(v.begin(), v.end()) - v.begin();
        init(size);
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            int l = lower_bound(v.begin(), v.begin() + size, node[i].X) - v.begin() + 1;
            int r = lower_bound(v.begin(), v.begin() + size, node[i].Y) - v.begin() + 1;
            int t1 = find(l), t2 = find(r);
            if (t1 != t2)
            {
                par[t2] = t1;
                if (parity[i][0] == 'o')
                    val[t2] = val[l] ^ val[r] ^ 1;
                else
                    val[t2] = val[l] ^ val[r];
            }
            else
            {
                if (val[l] == val[r] && parity[i][0] == 'o') break;
                else if (val[l] != val[r] && parity[i][0] == 'e') break;
            }
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
