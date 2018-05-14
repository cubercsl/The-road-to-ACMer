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
    int n;
    cin >> n;
    map<int, string> ans;
    string s[3];
    vector<int> cnt(3);
    cin >> s[0] >> s[1] >> s[2];
    ans[0] = "Draw";
    ans[1] = "Kuro";
    ans[2] = "Shiro";
    ans[3] = "Katie";
    for (int i = 0; i < 3; i++)
    {
        int m = s[i].length();
        map<char, int> M;
        for (auto c : s[i])
        {
            M[c]++;
            cnt[i] = max(cnt[i], M[c]);
        }
        if (cnt[i] == m && n == 1)
            cnt[i]--;
        else
            cnt[i] = min(cnt[i] + n, m);
    }
    int id = 0;
    if (cnt[0] > cnt[1] && cnt[0] > cnt[2])
        id = 1;
    else if (cnt[1] > cnt[0] && cnt[1] > cnt[2])
        id = 2;
    else if (cnt[2] > cnt[0] && cnt[2] > cnt[1])
        id = 3;
    cout << ans[id] << endl;
}