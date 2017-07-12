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

const int maxn = 505;
bool notprime[maxn] = {1, 1};
bool NP[maxn][maxn];
vector <int> prime;
void getprime()
{
    for (int i = 2; i < maxn; i++)
        if (!notprime[i] && i <= maxn / i)
            for (int j = i * i; j < maxn; j += i)
                notprime[j] = 1;
    for (int i = 0; i <= 500; i++)
        if (!notprime[i])
            prime.pb(i);
}

void solve()
{
    for (int i = 1; i <= 500; i++)
        for (int j = 1; j <= 500; j++)
            if (!NP[i][j])
                for (int k = 0; k < prime.size(); k++)
                {
                    if (i + prime[k] < maxn)
                        NP[i + prime[k]][j] = 1;
                    if (j + prime[k] < maxn)
                        NP[i][j + prime[k]] = 1;
                    if (i + prime[k] < maxn && j + prime[k] < maxn)
                        NP[i + prime[k]][j + prime[k]] = 1;
                }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin
    getprime();
    solve();
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;
        if (NP[m][n])
            cout << "Sora" << endl;
        else
            cout << "Shiro" << endl;
    }
    return 0;
}
