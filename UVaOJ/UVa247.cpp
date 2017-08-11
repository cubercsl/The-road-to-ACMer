// Calling Circles, ACM/ICPC World Finals 1996, UVa247

/*Sample Input
5 6
Ben Alexander
Alexander Dolly
Dolly Ben
Dolly Benedict
Benedict Dolly
Alexander Aaron
14 34
John Aaron
Aaron Benedict
Betsy John
Betsy Ringo
Ringo Dolly
Benedict Paul
John Betsy
John Aaron
Benedict George
Dolly Ringo
Paul Martha
George Ben
Alexander George
Betsy Ringo
Alexander Stephen
Martha Stephen
Benedict Alexander
Stephen Paul
Betsy Ringo
Quincy Martha
Ben Patrick
Betsy Ringo
Patrick Stephen
Paul Alexander
Patrick Ben
Stephen Quincy
Ringo Betsy
Betsy Benedict
Betsy Benedict
Betsy Benedict
Betsy Benedict
Betsy Benedict
Betsy Benedict
Quincy Martha
0 0
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

const int maxn = 30;
int n, m, tot;
map <string, int> dic;
vector <string> person;
bool G[maxn][maxn];
bool vis[maxn];

void add_edge(string a, string b)
{
    if (dic.find(a) == dic.end())
    {
        dic[a] = tot++;
        person.pb(a);
    }
    if (dic.find(b) == dic.end())
    {
        dic[b] = tot++;
        person.pb(b);
    }
    G[dic[a]][dic[b]] = 1;
}

void floyd()
{
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                G[i][j] |= (G[i][k] & G[k][j]);
}

void solve(int k)
{
    cout << "Calling circles for data set " << k << ":" << endl;
    clr(vis, 0);
    for (int i = 0; i < n; i++)
    {
        if (vis[i])
            continue;
        vis[i] = true;
        cout << person[i];
        for (int j = i + 1; j < n; j++)
            if (!vis[j] && (G[i][j]&G[j][i]))
            {
                cout << ", " << person[j];
                vis[j] = true;
            }
        cout << endl;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin
    int k = 0;
    while (cin >> n >> m, m + n)
    {
        if (k) cout << endl;
        dic.clear();
        person.clear();
        tot = 0;
        clr(G, 0);
        while (m--)
        {
            string a, b;
            cin >> a >> b;
            add_edge(a, b);
        }
        floyd();
        solve(++k);
    }
    return 0;
}
