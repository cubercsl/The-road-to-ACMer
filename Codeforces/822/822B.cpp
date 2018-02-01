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

const int maxn = 1005;

int main()
{
    int n, m, flag;
    char s[maxn], t[maxn];
    while (cin >> n >> m)
    {
        cin >> s >> t;
        int ans = INF;
        for (int i = 0; i <= m - n; i++)
        {
            int cnt = 0;
            for (int j = 0; j < n; j++)
            {
                if (s[j] != t[i + j])
                    cnt++;
            }
            if (cnt < ans)
                flag = i, ans = cnt;
        }
        cout << ans << endl;
        int first = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] != t[flag + i])
            {
                if (first++)
                    cout << " ";
                cout << i + 1;
            }
        }
        cout << endl;
    }
    return 0;
}
