// Intelligent IME, 2012 ACM/ICPC Asia Regional Tianjin Online, HDU4287

/*Sample Input
1
3 5
46
64448
74
go
in
night
might
gn
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

int  bot[] = {2, 2, 2,
              3, 3, 3,
              4, 4, 4,
              5, 5, 5,
              6, 6, 6,
              7, 7, 7, 7,
              8, 8, 8,
              9, 9, 9, 9,
             };
const int maxn = 5005;
map<int, int> dic;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin
    int t;
    string M[maxn];
    int N[maxn];
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        dic.clear();
        for (int i = 0; i < n; i++)
            cin >> N[i];
        for (int i = 0; i < m; i++)
        {
            cin >> M[i];
            int tmp = 0;
            for (int j = 0; j < M[i].length(); j++)
                tmp = tmp * 10 + bot[M[i][j] - 'a'];
            dic[tmp]++;
        }
        for (int i = 0; i < n; i++)
            cout << dic[N[i]] << endl;
    }

    return 0;
}
