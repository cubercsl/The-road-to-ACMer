// ybmj
#include <bits/stdc++.h>
using namespace std;
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define lson_len (len - (len >> 1))
#define rson_len (len >> 1)
#define pb(x) push_back(x)
#define clr(a, x) memset(a, x, sizeof(a))
#define mp(x, y) make_pair(x, y)
#define my_unique(a) a.resize(distance(a.begin(), unique(a.begin(), a.end())))
#define my_sort_unique(c) (sort(c.begin(), c.end())), my_unique(c)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
const int INF = 0x3f3f3f3f;
const int NINF = 0xc0c0c0c0;
const int maxn = 2e5 + 5;
string STD[20] = {"0000", "0001", "0010", "0011", "0100", "0101",
                  "0110", "0111", "1000", "1001", "1010", "1011",
                  "1100", "1101", "1110", "1111"};
map<string, char> maps;
char s[maxn];

string work()
{
    int len = strlen(s);
    string res;
    for (int i = 0; i < len; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
            res += STD[s[i] - '0'];
        else if (s[i] >= 'A' && s[i] <= 'Z')
            res += STD[s[i] - 'A' + 10];
        else
            res += STD[s[i] - 'a' + 10];
    }
    int pos = 0;
    len = res.size();
    string ans;
    while (pos + 8 < len)
    {
        string tmp;
        int cnt = 0;
        for (int i = 0; i < 8; i++)
        {
            if (res[pos + i] == '1') cnt++;
            tmp += res[pos + i];
        }
        if (((cnt & 1) && res[pos + 8] == '0') || ((cnt % 2 == 0) && res[pos + 8] == '1'))
        {
            ans += tmp;
        }
        pos += 9;
    }
    string ret;
    string tmp;
    len = ans.size();
    int p = 0;
    while (p < len)
    {
        tmp += ans[p];
        if (maps.find(tmp) != maps.end())
        {
            ret += maps[tmp];
            tmp = "";
        }
        p++;
    }
    return ret;
}
int main()
{
// /*
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    // */
    std::ios::sync_with_stdio(false);
    int T;
    scanf("%d", &T);
    while (T--)
    {
        maps.clear();
        int m, n;
        scanf("%d%d", &m, &n);
        char tmp[100];
        for (int i = 0, x; i < n; i++)
        {
            scanf("%d%s", &x, tmp);
            string s1(tmp);
            maps[s1] = char(x);
        }
        scanf("%s", s);
        puts(work().substr(0, m).c_str());
    }
}