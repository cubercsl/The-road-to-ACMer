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

const int maxn = 5e5 + 5;
int m[maxn], w[maxn];
double f[maxn];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, k;
    double a;
    while (cin >> n >> k >> a)
    {
        for (int i = 0; i < n; i++)
            cin >> m[i] >> w[i];
        double L = 0, R = 1e4;
        while (fabs(R - L) > eps)
        {
            double M = (L + R) / 2;
            for (int i = 0; i < n; i++) f[i] = m[i] - M * w[i];
            sort(f, f + n, [](double a, double b) { return a > b; });
            double sum = 0;
            for (int i = 0; i < k; i++) sum += f[i];
            if (sum > 0)
                L = M;
            else
                R = M;
        }
        if (L < a - eps)
            cout << "Hit Yaoge" << endl;
        else
            cout << fixed << setprecision(2) << L << endl;
    }
    return 0;
}
