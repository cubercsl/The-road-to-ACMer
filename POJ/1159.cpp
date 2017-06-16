//Palindrome, POJ1159

/*Sample Input
5
Ab3bd
*/

#include <iostream>
using namespace std;

char S[5010];
int n;
short dp[5010][5010];

void solve()
{
    for (int i = 1; i < n; i++)
        if (S[i - 1] != S[i])
            dp[i - 1][i] = 1;
    for (int k = 2; k < n; k++)
        for (int i = 0, j = k; j < n; i++, j++)
            if (S[i] == S[j])
                dp[i][j] = dp[i + 1][j - 1];
            else
                dp[i][j] = min(dp[i][j - 1], dp[i + 1][j]) + 1;
    cout << dp[0][n - 1] << endl;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> S[i];
    solve();
    return 0;
}
