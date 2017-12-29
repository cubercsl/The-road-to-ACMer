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

const int maxn = 1 << 17;
bool notprime[maxn] = {1, 1}; // 0 && 1 为非素数
void GetPrime()
{
    for (int i = 2; i < maxn; i++)
        if (!notprime[i] && i <= maxn / i) // 筛到√n为止
            for (int j = i * i; j < maxn; j += i)
                notprime[j] = 1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    GetPrime();
    while (~scanf("%d", &n) && n)
    {
        int cnt = 0;
        for (int i = 1; i <= n / 2; i++)
            if (!notprime[i] && !notprime[n - i]) cnt++;
        printf("%d\n", cnt);
    }

    return 0;
}
