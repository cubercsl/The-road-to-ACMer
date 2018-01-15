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

int cnt[10];
int digit[20], a[20];
int tot;
bool flag;
void dfs(int pos, bool lead = true, bool limit = true)
{
    if (flag) return;
    if (pos == -1)
    {
        for (int i = tot - 1; ~i; i--)
            cout << a[i];
        flag = true;
        cout << endl;
        return;
    }
    int up = limit ? digit[pos] : 9;
    for (int i = up; ~i; i--)
    {
        if (lead && i == 0) continue;
        if (cnt[i] > 0)
        {
            cnt[i]--;
            a[pos] = i;
            dfs(pos - 1, lead && i == 0, limit && i == digit[pos]);
            cnt[i]++;
        }
    }
}

void solve(ll a, ll b)
{
    string A = to_string(a);
    string B = to_string(b);
    if (A.length() < B.length())
    {
        sort(A.begin(), A.end());
        reverse(A.begin(), A.end());
        cout << A << endl;
        return;
    }
    clr(cnt, 0);
    int pos = 0;
    do
        digit[pos++] = b % 10;
    while (b /= 10);
    do
        cnt[a % 10]++;
    while (a /= 10);
    // for (int i = 0; i < 10; i++) cout << cnt[i] << endl;
    tot = pos;
    flag = false;
    dfs(pos - 1);
}

int main()
{
#ifndef ONLINE_JUDGE
    // freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
#endif
    ll a, b;
    while (cin >> a >> b)
        solve(a, b);
    return 0;
}
