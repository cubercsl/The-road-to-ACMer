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

const int maxn = 1e6 + 5;

int main()
{
    int n,a;
    while (~scanf("%d", &n))
    {
        int cnt = 0;
        bool flag = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a);
            if (a & 1) flag = 1;
        }
        flag ? puts("First") : puts("Second");
    }
    return 0;
}
