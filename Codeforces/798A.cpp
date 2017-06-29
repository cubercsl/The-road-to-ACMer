#include <bits/stdc++.h>
#define input(n) while(cin >> n)
#define input_2(a, b) while(cin >> a >> b)
#define Tcase int T; cin >> T; while(T--)
#define clr(x, y) memset(x, y, sizeof(x))
#define pb push_back
#define mp make_pair
#define lowbit(x) (x & -x)
#define Lson L, mid, node << 1
#define Rson mid + 1, R, node << 1 | 1
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;

int main()
{
    char s[20];
    while (cin >> s)
    {
        int cnt = 0;
        int len = strlen(s);
        // cout << len << endl;
        for (int i = 0; i < len / 2; i++)
        {
            if (s[i] != s[len - 1 - i])
                cnt++;
        }
        if (cnt == 1)
            cout << "YES" << endl;
        else if (len % 2 && cnt == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
