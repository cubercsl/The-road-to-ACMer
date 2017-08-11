// Period II, FZU1901

/*Sample Input
4
ooo
acmacmacmacmacma
fzufzufzuf
stostootssto
*/

#include <iostream>
#include <vector>
#include <string>
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

const int maxn  = 1e6 + 5;
int ne[maxn];
vector <int> v;
void init(string s, int n)
{
    int i = 0, j = -1;
    ne[0] = -1;
    while (i < n)
    {
        while (j != -1 && s[i] != s[j])
            j = ne[j];
        ne[++i] = ++j;
    }
}

int main()
{
    fastin
    string s;
    int t, kase = 0;
    cin >> t;
    while (t--)
    {
        v.clear();
        cin >> s;
        init(s, s.length());
        for (int i = s.length(); i > 0; i = ne[i])
            v.pb(s.length() - ne[i]);

        cout << "Case #" << ++kase << ": " << v.size() << endl;
        for (int i = 0; i < v.size(); i++)
        {
            if (i)cout << " ";
            cout << v[i];
        }
        cout << endl;
    }
    return 0;
}
