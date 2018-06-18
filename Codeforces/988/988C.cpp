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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int k;
    cin >> k;
    vector<vector<int> > a(k);
    map<int, PII> M;
    int id = 0;
    for (auto& t : a)
    {
        ++id;
        int n;
        cin >> n;
        t.resize(n);
        for (auto& tt : t) cin >> tt;
        int sum = accumulate(t.begin(), t.end(), 0);
        sum -= t[0];
        if (M.find(sum) != M.end())
        {
            if (M[sum].X == id) continue;
            cout << "YES" << endl;
            cout << M[sum].X << " " << M[sum].Y << endl;
            cout << id << " " << 1 << endl;
            return 0;
        }
        M[sum] = {id, 1};
        for (int i = 1; i < n; i++)
        {
            sum += t[i - 1];
            sum -= t[i];
            if (M.find(sum) != M.end())
            {
                if (M[sum].X == id) continue;
                cout << "YES" << endl;
                cout << M[sum].X << " " << M[sum].Y << endl;
                cout << id << " " << i + 1 << endl;
                return 0;
            }
            M[sum] = {id, i + 1};
        }
    }
    cout << "NO";

    return 0;
}