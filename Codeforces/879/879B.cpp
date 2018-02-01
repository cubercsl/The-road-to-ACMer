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

const int maxn = 505;
int n, k;
int cnt[maxn];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    ll k;
    int a[maxn];
    while (cin >> n >> k)
    {
        deque<int> q;
        int buf;
        for (int i = 0; i < n; i++)
        {
            cin >> buf;
            q.push_back(buf);
        }
        if (k >= n * 2)
        {
            cout << n << endl;
            continue;
        }
        while (true)
        {
            int a = q.front();
            q.pop_front();
            int b = q.front();
            q.pop_front();
            if (a > b)
            {
                cnt[a]++;
                q.push_front(a);
                q.push_back(b);
                if (cnt[a] == k) break;
            }
            else
            {
                cnt[b]++;
                q.push_front(b);
                q.push_back(a);
                if (cnt[b] == k) break;
            }
        }
        cout << q.front() << endl;
    }
    return 0;
}
