#include <bits/stdc++.h>
using namespace std;
#define clr(a,x) memset(a, x, sizeof(a))
#define mp(x,y) make_pair(x,y)
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

const int maxn = 3e5 + 5;
struct Node
{
    int a, id;
    bool operator<(const Node &rhs) const
    {
        return a > rhs.a || (a == rhs.a && id < rhs.id);
    }
} node[maxn];

bool vis[maxn];
int ans[maxn];

int main()
{
    int n, k;
    while (cin >> n >> k)
    {
        set<int> s;
        for (int i = 1; i <= n; i++)
            s.insert(k + i);
        for (int i = 0; i < n; i++)
        {
            cin >> node[i].a;
            node[i].id = i + 1;
        }
        sort(node, node + n);
        ll sum = 0;
        clr(vis, 0);
        for (int i = 0; i < n; i++)
        {
            int j = max(node[i].id, k + 1);
            j = *s.lower_bound(j);
            sum += (ll)(j - node[i].id) * (ll)node[i].a;
            ans[node[i].id - 1] = j;
            s.erase(j);
        }
        cout << sum << endl;
        for (int i = 0; i < n; i++)
        {
            if (i)
                cout << " ";
            cout << ans[i];
        }
        cout << endl;
    }
    return 0;
}
