// Cheapest Palindrome, POJ3280

/*Sample Input
3 4
abcb
a 1000 1100
b 350 700
c 200 800
*/

#include <iostream>
using namespace std;

const int maxn = 2005;
int dp[maxn][maxn];
char a[maxn];
int v[26];
int n, m;

int solve()
{
    for (int i = m - 1; i >= 0; i--)
        for (int j = i; j < m; j++)
        {
            if (a[i] == a[j])
                dp[i][j] = dp[i + 1][j - 1];
            else
                dp[i][j] = min(dp[i + 1][j] + v[a[i] - 'a'], dp[i][j - 1] + v[a[j] - 'a']);
        }
    return dp[0][m - 1];
}

int main()
{
    cin >> n >> m;
    cin >> a;
    while (n--)
    {
        char ch;
        int add, del;
        cin >> ch >> add >> del;
        v[ch - 'a'] = min(add, del);
    }
    cout << solve() << endl;
    return 0;
}
