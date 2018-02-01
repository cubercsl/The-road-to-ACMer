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

const int maxn = 1 << 17;

int main()
{
#ifndef ONLINE_JUDGE
// freopen("1.in", "r", stdin);
// freopen("1.out", "w", stdout);
#endif
    int n;
    int a[maxn];
    while (cin >> n)
    {
        priority_queue<int> q;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int now = n;
        for (int i = 0; i < n; i++)
        {
            // cout << "!!!" << a[i] << endl;
            q.push(a[i]);
            while(!q.empty())
            {
                int tmp = q.top();
                if(tmp == now)
                {
                    cout << now << " ";
                    now--;
                    q.pop();
                }
                else 
                    break;
            }
            cout << endl;
        }
    }
    return 0;
}