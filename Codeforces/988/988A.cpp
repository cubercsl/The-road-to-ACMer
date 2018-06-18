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
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    set<int> s;
    for (auto& t : v) cin >> t;
    for (auto& t : v) s.insert(t);
    if (s.size() < k) return cout << "NO", 0;
    s.clear();
    cout << "YES" << endl;
    int id = 0, cnt = 0;
    for(auto& t : v)
    {
        ++id;
        if(s.find(t) == s.end())
        {
            cout << id << " ";
            if(++cnt == k) return 0;
            s.insert(t);
        }
    }
    assert(false);
    return 0;
}