#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 17;
char s[N];
char t[N];
int dp[N][26];
void build(const char* s)
{
    int n = strlen(s);
    for (int i = 0; i < 26; i++) dp[n][i] = n;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < 26; j++)
            dp[i][j] = dp[i + 1][j];
        dp[i][s[i] - 'a'] = i;
    }

}

int main()
{
    scanf("%s%s", s, t);
    build(s);
    long long ans = 0;
    int n = strlen(s), m = strlen(t);
    for (int i = 0; i < n; i++)
    {
        int u = i;
        for (int j = 0; j < m && u <= n; j++) u = dp[u][t[j] - 'a'] + 1;
        ans += n - u + 1;
    }
    printf("%lld\n", ans);
}