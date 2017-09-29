// Secretary, POJ2217

/*Sample Input
2
Tady nejsou zadni mimozemstani.
Lide tady take nejsou.
Ja do lesa nepojedu.
V sobotu pojedeme na vylet.
*/

#include <cstring>
#include <iostream>
#include <string>
#include <vector>
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

const int maxn = 1e4 + 5;
int sa[maxn], t[maxn], t2[maxn], c[maxn];

void build_sa(const string& s, int m)
{
    int n = s.length() + 1;
    int *x = t, *y = t2;
    for (int i = 0; i < m; i++) c[i] = 0;
    for (int i = 0; i < n; i++) c[x[i] = s[i]]++;
    for (int i = 1; i < m; i++) c[i] += c[i - 1];
    for (int i = n - 1; ~i; i--) sa[--c[x[i]]] = i;
    for (int k = 1; k <= n; k <<= 1)
    {
        int p = 0;
        for (int i = n - k; i < n; i++) y[p++] = i;
        for (int i = 0; i < n; i++)
            if (sa[i] >= k) y[p++] = sa[i] - k;
        for (int i = 0; i < m; i++) c[i] = 0;
        for (int i = 0; i < n; i++) c[x[y[i]]]++;
        for (int i = 0; i < m; i++) c[i] += c[i - 1];
        for (int i = n - 1; ~i; i--) sa[--c[x[y[i]]]] = y[i];
        swap(x, y);
        p = 1;
        x[sa[0]] = 0;
        for (int i = 1; i < n; i++)
            x[sa[i]] = y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + k] == y[sa[i] + k] ? p - 1 : p++;
        if (p >= n) break;
        m = p;
    }
}

int rnk[maxn], height[maxn];
void getheight(const string& s)
{
    int n = s.length() + 1;
    int k = 0;
    for (int i = 0; i < n; i++) rnk[sa[i]] = i;
    for (int i = 0; i < n; i++)
    {
        if (k) k--;
        int j = sa[rnk[i] - 1];
        while (s[i + k] == s[j + k]) k++;
        height[rnk[i]] = k;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int N;
    string S, T;
    cin >> N;
    getline(cin, S);
    while (N--)
    {
        getline(cin, S);
        int len = S.length();
        getline(cin, T);
        S += '$' + T;
        build_sa(S, 128);
        getheight(S);
        // for (int i = 0; i <= S.length(); i++)
        // cout << height[i] << " ";
        // cout << endl;
        int ans = 0;
        for (int i = 2; i <= S.length(); i++)
            if ((sa[i] <= len) ^ (sa[i - 1] <= len))
                ans = max(ans, height[i]);
        cout << "Nejdelsi spolecny retezec ma delku " << ans << ".\n";
    }
    return 0;
}
