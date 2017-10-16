// DNA sequence, HDU1560

/*Sample Input
1
4
ACGT
ATGC
CGTT
CAGT
*/

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

const char c[] = "ACGT";
string s[10];

int get_h(int pos[], int n)
{
    int ret = 0;
    for (int i = 0; i < n; i++)
        ret = max(ret, (int)s[i].length() - pos[i]);
    return ret;
}

bool dfs(int id, int pos[], int n, int dep)
{
    int h = get_h(pos, n);
    if (id + h > dep) return false;
    if (!h) return true;
    int tmp[10];
    for (int i = 0; i < 4; i++)
    {
        bool flag = 0;
        for (int j = 0; j < n; j++)
        {
            if (s[j][pos[j]] == c[i])
                tmp[j] = pos[j] + 1, flag = 1;
            else
                tmp[j] = pos[j];
        }
        if (flag && dfs(id + 1, tmp, n, dep)) return true;
    }
    return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T;
    cin >> T;
    while (T--)
    {
        int n, dep = 0;
        int pos[10];
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
            dep = max(dep, (int)s[i].length());
            pos[i] = 0;
        }
        for (; !dfs(0, pos, n, dep); dep++)
            ;
        cout << dep << endl;
    }

    return 0;
}
