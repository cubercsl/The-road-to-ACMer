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

bool ok(int mid, const string& s)
{
    // cout << mid << endl;
    int n = s.length();
    int tong[26];
    clr(tong, 0);
    bool vis[26];
    for (int i = 0; i < 26; i++) vis[i] = 1;
    deque<char> q;
    for (int i = 0; i < mid; i++) q.push_back(s[i]), tong[s[i] - 'a']++;
    for (int j = 0; j < 26; j++)
        if (!tong[j]) vis[j] = 0;
    for (int i = mid; i < n; i++)
    {
        char tmp = q.front();
        // cout << tmp;
        tong[tmp - 'a']--;
        q.pop_front();
        tong[s[i] - 'a']++;
        q.push_back(s[i]);
        for (int j = 0; j < 26; j++)
            if (!tong[j]) vis[j] = 0;
    }
    // cout << endl;
    for (int i = 0; i < 26; i++)
        if (vis[i]) return true;
    return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    // freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
#endif
    string s;
    while (cin >> s)
    {
        int L = 1, R = s.length(), ans = 0;
        while (L <= R)
        {
            int mid = L + R >> 1;
            if (ok(mid, s))
                R = mid - 1, ans = mid;
            else
                L = mid + 1;
        }
        cout << ans << endl;
    }

    return 0;
}
