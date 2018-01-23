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
        int cnt = 0;
        int n, m;
        cin >> n >> m;
        queue<int> q;
        set<int> s;
        int num;
        for (int i = 0; i < m; i++)
        {
            cin >> num;
            if (s.find(num) != s.end())
                cnt++;
            else
            {
                if (q.size() < n)
                    q.push(num);
                else
                {
                    s.erase(q.front());
                    q.pop();
                    q.push(num);
                }
                s.insert(num);
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
