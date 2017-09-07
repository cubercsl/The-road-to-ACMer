#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
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
const double eps = 1e-6;
typedef unsigned long long ull;

const int maxn = 1e5 + 5;
char s[maxn], t[maxn];
ull h1[maxn], h2[maxn], Pow[maxn];
int slen, tlen;

ull gethash(ull h[], int l, int r)
{
    return h[r] - h[l] * Pow[r - l];
}

bool solve(int len)
{
    vector<int> v;
    for (int i = len; i <= slen; i++)
        v.pb(gethash(h1, i - len, i));
    for (int i = len; i <= tlen; i++)
    {
        ull tmp = gethash(h2, i - len, i);
        if (binary_search(v.begin(), v.end(), tmp)) return true;
    }
    return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    scanf("%s%s", s, t);
    slen = strlen(s);
    tlen = strlen(t);
    int L = 0, R = max(slen, tlen);
    Pow[0] = 1;
    for (int i = 1; i <= R; i++)
        Pow[i] = Pow[i - 1] * 131;
    h1[0] = h2[0] = 0;
    for (int i = 0; i < slen; i++)
        h1[i + 1] = h1[i] * 131 + s[i];
    for (int i = 0; i < tlen; i++)
        h2[i + 1] = h2[i] * 131 + t[i];
    int ans;
    while (L <= R)
    {
        int mid = (L + R) >> 1;
        if (solve(mid))
            L = mid + 1, ans = mid;
        else
            R = mid - 1;
    }
    printf("%d\n", ans);
    return 0;
}
