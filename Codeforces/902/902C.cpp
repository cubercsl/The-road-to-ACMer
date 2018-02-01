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

const int N = 1e6 + 7;

int a[N];
int pre_sum[N];
bool judge(int n)
{
    for (int i = 0; i < n; i++)
        if (a[i] > 1 && a[i + 1] > 1)
            return true;
    return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    while (cin >> n)
    {
        for (int i = 0; i <= n; i++)
            cin >> a[i];
        if (judge(n))
        {
            cout << "ambiguous" << endl;
            pre_sum[0] = a[0];
            for (int i = 1; i <= n; i++)
                pre_sum[i] = pre_sum[i - 1] + a[i];
            cout << 0;
            for (int i = 1; i <= n; i++)
                for (int j = 0; j < a[i]; j++)
                    cout << " " << pre_sum[i - 1];
            cout << endl;
            int flag = 0;
            cout << 0;
            for (int i = 1; i <= n; i++)
            {
                if (!flag && a[i - 1] > 1 && a[i] > 1)
                {
                    for (int j = 0; j < a[i] - 1; j++)
                        cout << " " << pre_sum[i - 1];
                    cout << " " << pre_sum[i - 1] - 1;
                    flag = 1;
                }
                else
                {
                    for (int j = 0; j < a[i]; j++)
                        cout << " " << pre_sum[i - 1];
                }
            }
            cout << endl;
        }
        else
            cout << "perfect" << endl;
    }
}
