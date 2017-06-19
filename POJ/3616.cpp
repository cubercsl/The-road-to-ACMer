// Milking Time, POJ3616

/*
12 4 2
1 2 8
10 12 19
3 6 24
7 10 31
*/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 1002;
int n, m, r, ans;
int dp[maxn];

struct node
{
    int st, en, ef;
    bool operator < (const node &b) const
    {
        return st < b.st;
    }
} s[maxn];

int solve()
{
    ans = -1;
    for (int i = 0; i < m; i++)
    {
        dp[i] = s[i].ef;
        for (int j = 0; j < i; j++)
            if (s[j].en + r <= s[i].st)
                dp[i] = max(dp[i], dp[j] + s[i].ef);
        ans = max(ans, dp[i]);
    }
    return ans;
}


int main()
{
    cin >> n >> m >> r;
    for (int i = 0; i < m; i++)
        cin >> s[i].st >> s[i].en >> s[i].ef;
    sort(s, s + m);
    cout << solve() << endl;
    return 0;
}
