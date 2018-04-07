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

const int N = 1 << 17;
bool vis[N];
int cnt[26];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    string s;
    int k;
    cin >> s >> k;
    int id[26];
    for (int i = 0; i < 26; i++) id[i] = i;
    for (auto& t : s) cnt[t - 'a']++;
    sort(id, id + 26, [](int a, int b) {
        return cnt[a] < cnt[b];
    });
    for (int i = 0; i < 26 && k > 0; i++)
    {
        int c = id[i];
        for (int j = 0; j < s.length() && k > 0; j++)
            if (s[j] == 'a' + c) vis[j] = true, k--;
    }
    string ans;
    set<char> ss;
    for (int i = 0; i < s.length(); i++)
        if (!vis[i]) ans.pb(s[i]);
    for (auto& t : ans) ss.insert(t);
    cout << ss.size() << endl;
    cout << ans << endl;
    return 0;
}
