// Sumsets, POJ2229

/*Sample Input
7
*/

#include <iostream>
using namespace std;

int n;
int dp[1000010];
const int mod = 1e9;

int main()
{
    cin >> n;
    dp[0] = 1;
    for (int i = 1; i <= n; i <<= 1)
        for (int j = i; j <= n; j++)
            dp[j] = (dp[j] + dp[j - i]) % mod;
    cout << dp[n] << endl;
    return 0;
}
