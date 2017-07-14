// Goldbach's Conjecture, POJ2262

/*Sample Input
8
20
42
0
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
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

const int maxn = 1e6 + 5;
bool notprime[maxn] = {1, 1};
void init()
{
    for (int i = 2; i < maxn; i++)
        if (!notprime[i] && i <= maxn / i)
            for (int j = i * i; j < maxn; j += i)
                notprime[j] = 1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    init();
    int n;
    while (cin >> n, n)
    {
        for (int i = 3; i <= n / 2; i += 2)
            if (!notprime[i] && !notprime[n - i])
            {
                cout << n << " = " << i << " + " << n - i << endl;
                break;
            }
    }
    return 0;
}
