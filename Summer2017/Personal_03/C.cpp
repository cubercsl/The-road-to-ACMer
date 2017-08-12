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

const int maxn = 500005;
int Min(char *s, int l) //串s[0~l-1]的最小表示位置
{
    int i = 0, j = 1, k = 0, t;
    while (i < l && j < l && k < l)//找不到比它还小的 或者 完全匹配
    {
        t = s[(i + k) % l] - s[(j + k) % l];
        if (t == 0)
            k++;
        else
        {
            if (t > 0)
                i += k + 1;
            else
                j += k + 1;
            if (i == j)
                j++;
            k = 0;
        }
    }
    return min(i, j);
}

int main()
{
    char s[maxn];
    int n;
    cin>>n;
    cin>>s;


    return 0;
}
