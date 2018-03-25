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

inline char gao(char x)
{
    if (x == '-') return '|';
    if (x == '|') return '-';
    return '+';
}

const int N = 40;
char s[N][N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++) cin >> s[i];
        string op;
        cin >> op;
        int dir = 0;
        for (auto& t : op)
        {
            if (t == 'L')
                dir--;
            else
                dir++;
            (dir += 4) %= 4;
        }
        if (dir == 0)
        {
            cout << n << " " << m << endl;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                    cout << s[i][j];
                cout << endl;
            }
        }
        else if (dir == 1)
        {
            cout << m << " " << n << endl;
            for (int i = 0; i < m; i++)
            {
                for (int j = n - 1; ~j; j--)
                    cout << gao(s[j][i]);
                cout << endl;
            }
        }
        else if (dir == 2)
        {
            cout << n << " " << m << endl;
            for (int i = n - 1; ~i; i--)
            {
                for (int j = m - 1; ~j; j--)
                    cout << s[i][j];
                cout << endl;
            }
        }
        else
        {
            cout << m << " " << n << endl;
            for (int i = m - 1; ~i; i--)
            {
                for (int j = 0; j < n; j++)
                    cout << gao(s[j][i]);
                cout << endl;
            }
        }
        cout << endl;
    }
    return 0;
}
