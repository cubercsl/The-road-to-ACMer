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

int cnt[30];

int main()
{
    int n, k;
    char s[105];
    while (cin >> n >> k)
    {
        cin >> s;
        clr(cnt, 0);
        for (int i = 0; i < n; i++)
            cnt[s[i] - 'a']++;
        bool flag = 1;
        for (int i = 0; i < 26; i++)
            if (cnt[i] > k)
            {
                flag = 0;
                break;
            }
        flag ? puts("YES") : puts("NO");
    }
    return 0;
}
