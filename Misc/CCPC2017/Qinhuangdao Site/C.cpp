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

char gao[] = "gao";

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T;
    string s;
    cin >> T;
    while (T--)
    {
        cin >> s;
        int Ans = 0;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                for (int k = 0; k < 3; k++)
                {
                    int ans = 0;
                    if (i == j || j == k || i == k)
                        continue;
                    string A;
                    int cnt = 0;
                    for (auto t : s)
                    {
                        if (t == gao[i])
                            cnt++;
                        else
                            cnt = 0, A.pb(t);
                        if (cnt == 3) ans++;
                    }
                    cnt = 0;
                    for (auto t : A)
                    {
                        if (t == gao[j])
                            cnt++;
                        else
                            cnt = 0;
                        if (cnt == 3) ans++;
                    }
                    Ans = max(ans + 1,Ans);
                }
        cout << Ans << endl;
    }
    return 0;
}
