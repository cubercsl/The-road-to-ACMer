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

const int maxn = 50;
ll C[maxn][maxn];
void CalComb()
{
    C[0][0] = 1;
    for (int i = 1; i < maxn; i++)
    {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
}

vector<string> v = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q"};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    CalComb();
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        unordered_map<string, int> M;
        string s;
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            M[s]++;
        }
        int m = 48 - n, a = 4 - M["A"];
        ll dp[5] = {};
        ll tp[5] = {};
        for (int i = 1; i <= m - a; i++)
            dp[1] += C[a + i - 1][a - 1] * i;
        for (int i = 2; i <= m - a; i++)
            dp[2] += C[a + i - 1][a - 1] * i * (i - 1);
        for (int i = 3; i <= m - a; i++)
            dp[3] += C[a + i - 1][a - 1] * i * (i - 1) * (i - 2);
        for (int i = 4; i <= m - a; i++)
            dp[4] += C[a + i - 1][a - 1] * i * (i - 1) * (i - 2) * (i - 3);
        tp[1] = C[m][a] * (m - a);
        tp[2] = C[m][a] * (m - a) * (m - a - 1);
        tp[3] = C[m][a] * (m - a) * (m - a - 1) * (m - a - 2);
        tp[4] = C[m][a] * (m - a) * (m - a - 1) * (m - a - 2) * (m - a - 3);
        cout << 1;
        for (auto& t : v)
        {
            if (t == "A") continue;
            cout << " ";
            int r = 4 - M[t];
            if (r == 0)
                cout << 1;
            else
            {
                ll d = __gcd(dp[r], tp[r]);
                if (dp[r] == 0)
                    cout << 0;
                else
                    cout << dp[r] / d << "/" << tp[r] / d;
            }
        }
        cout << endl;
    }
    return 0;
}
