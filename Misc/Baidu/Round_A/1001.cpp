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

int main()
{
    fastin
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        n--;
        int cnt = 0;
        for (int i = 1; i < sqrt(n); i++)
        {
            if (n % i == 0)
                cnt += 2;
        }
        if (n % (int)sqrt(n) == 0)
            cnt++;
        cout << cnt << endl;
    }

    return 0;
}
