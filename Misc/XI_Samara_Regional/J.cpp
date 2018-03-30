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

const int N = 1 << 18;
int cnt[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, c;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> c;
        cnt[c]++;
    }
    sort(cnt, cnt + N, greater<int>());
    int ans = 0;
    for (int i = 0; i < N; i++) ans += cnt[i] / 2;
    cout << ans / 2 << endl;
    return 0;
}
