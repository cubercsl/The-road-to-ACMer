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
string name[6][20];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int T;
    int kase = 0;
    cin >> T;
    while (T--) {
        int G;
        string line;
        cin >> G >> line;
        for (int i = 0; i < 6; i++) {
            for (int k = 0; k < 20; k++) {
                cin >> name[i][k];
            }
        }
        set<string> S;
        int x = 0, y = 0;
        bool flag = false;
        for (int i = 0; i < 20; i++) {
            for (int k = 0; k < 5; k++) {
                if (name[k][i] == line || x == G) {
                    flag = true;
                    break;
                }
                if (S.find(name[k][i]) == S.end()) {
                    S.insert(name[k][i]);
                    x++;
                }
            }
            if (flag) break;
        }

        cout << "Case #" << ++kase << ": ";
        if (x == G) {
            cout << 0 << endl;
        }
        else
        {
            y = G - x;
            for (int i = 0; i < 20; i++) {
                if (line == name[5][i]) break;
                if (S.find(name[5][i]) == S.end()) {
                    S.insert(name[5][i]);
                    y--;
                }
                if (y == 0) {
                    break;
                }
            }
            if (y)
                cout << "ADVANCED!" << endl;
            else
                cout << G - x << endl;
        }
    }
}
