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

int main()
{
    int n, m;
    queue<int> q;
    while (cin >> n >> m)
    {
        while (n--)
        {
            int num;
            cin >> num;
            q.push(num);
        }
        int cnt = 1;
        int now = 0;
        while (!q.empty())
        {
            int tmp = q.front();
            q.pop();
            now += tmp;
            if (now > m)
                now = tmp, cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}
