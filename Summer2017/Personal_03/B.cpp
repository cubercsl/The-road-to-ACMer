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
char preo[maxn];
char ino[maxn];

void dfs(int s1, int t1, int s2, int t2)
{
    int rt;
    if (s1 > t1) return;
    for (rt = s2; ino[rt] != preo[s1]; rt++);
    dfs(s1 + 1, s1 + rt - s2, s2, rt - 1);
    dfs(s1 + rt - s2 + 1, t1, rt + 1, t2);
    cout << ino[rt];
}

int main()
{
    while (cin >> preo >> ino)
    {
        int l = strlen(preo) - 1;
        dfs(0, l, 0, l);
        cout << endl;
    }
    return 0;
}
