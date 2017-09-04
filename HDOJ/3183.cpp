// A Magic Lamp, HDU3183

/*Sample Input
178543 4 
1000001 1
100001 2
12345 2
54321 2
*/

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

const int maxn = 1e3 + 5;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin
    char s[maxn], ans[maxn];
    int m;
    while (cin >> s >> m)
    {
        int l = 0, r = m + 1, id = 0;
        m = strlen(s) - m;
        while (m--)
        {
            l = min_element(s + l, s + r) - s;
            ans[id++] = s[l++];
            r++;
        }
        ans[id] = 0;
        int head = 0;
        while (ans[head] == '0') head++;
        if (head == id) puts("0");
        else puts(ans + head);
    }
    return 0;
}
