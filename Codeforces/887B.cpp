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

const int maxn = 5005;
int a[maxn], b[maxn];

int main()
{
    string s;
    while (cin >> s)
    {
        int ans = -1, n = s.length();
        for (int i = 0; i < n; i++)
            a[i + 1] = a[i] + (s[i] == 'a'), b[i + 1] = b[i] + (s[i] == 'b');
        /*for(int i = 1; i <= n; i++)
			cout << a[i] <<endl;
		for(int i = 1; i <= n; i++)
			cout << b[i] << endl;*/
        for (int i = 0; i < n; i++)
            if (s[i] == 'b')
                for (int j = i; j < n; j++)
                    if (s[j] == 'b')
                    {
                        int tmp = n - (a[j + 1] - a[i]) - b[i] - (b[n] - b[j + 1]);
                        ans = max(ans, tmp);
                    }
        cout << (~ans ? ans : n) << endl;
    }
    return 0;
}
