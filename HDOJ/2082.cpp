// 找单词, HDU2082

/*Sample Input
2
1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
9 2 6 2 10 2 2 5 6 1 0 2 7 0 2 2 7 5 10 6 10 2 10 6 1 9
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

const int maxn = 55;
int num[maxn];
int a[maxn], b[maxn];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin
    int t;
    cin >> t;
    while (t--)
    {
        for (int i = 1; i <= 26; i++)
            cin >> num[i];
        clr(a, 0);
        clr(b, 0);
        for (int i = 0; i <= num[1]; i++)
            a[i] = 1;
        for (int i = 2; i <= 26; i++)
        {
            if (num[i] == 0) continue;
            for (int j = 0; j <= 50; j++)
                for (int k = 0; k <= num[i] && j + k * i <= 50; k++)
                    b[j + k * i] += a[j];
            for (int j = 0; j <= 50; j++)
                a[j] = b[j];
            clr(b, 0);
        }
        int sum = 0;
        for (int i = 1; i <= 50; i++)
            sum += a[i];
        cout << sum << endl;
    }
    return 0;
}
