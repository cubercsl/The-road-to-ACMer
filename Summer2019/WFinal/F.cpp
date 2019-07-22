#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
typedef pair<int, int> pii;

char s[maxn];
int dp[maxn][26][12];
pii tmp[30];
int ans[30];
pii last[30];

int main()
{
    int n, l, K;
    while (~scanf("%d%d%d", &n, &l, &K))
    {
        scanf("%s", &s);

        memset(dp, 0x3f, sizeof(dp));
        for (int i = 0; i < 26; i++) dp[0][i][1] = (i == (s[0] - 'a')) ? 0 : 1;

        for (int k = 1; k <= K; k++)
        {
            deque<pii> dq[2][26];
            for (int j = 0; j < 26; j++)
            {
                dq[1][j].push_back(make_pair(0, (s[0] - 'a' != j)));
                dq[0][j].push_back(make_pair(0, (s[0] - 'a' != j)));
            }

            for (int i = 1; i < n; i++)
            {
                for (int j = 0; j < 26; j++)
                {
                    while (dq[1][j].size() && i - dq[1][j].front().first > l) dq[1][j].pop_front();
                    while (dq[0][j].size() && i - dq[0][j].front().first > l) dq[0][j].pop_front();
                }
                for (int j = 0; j < 26; j++)
                {
                    ans[j] = dq[1][j].front().second;
                    tmp[j] = {dq[0][j].front().second, j};
                    last[j] = {dp[i - 1][j][k - 1], j};
                }
                nth_element(last, last + 1, last + 26);
                nth_element(tmp, tmp + 1, tmp + 26);

                for (int j = 0; j < 26; j++)
                {
                    if (j == s[i] - 'a')
                    {
                        dp[i][j][k] = dp[i - 1][j][k];
                        if (last[0].second == j)
                            dp[i][j][k] = min(dp[i][j][k], last[1].first);
                        else
                            dp[i][j][k] = min(dp[i][j][k], last[0].first);
                        // if(s[i] != s[i-1])
                        //     dp[i][j][k] = dp[i-1][j][k-1];
                        // else dp[i][j][k] = dp[i-1][j][k];
                    }
                    else
                    {
                        dp[i][j][k] = ans[j];
                        if (tmp[0].second == j)
                            dp[i][j][k] = min(dp[i][j][k], tmp[1].first);
                        else
                            dp[i][j][k] = min(dp[i][j][k], tmp[0].first);
                        dp[i][j][k]++;
                    }
                }

                for (int j = 0; j < 26; j++)
                {
                    while (dq[1][j].size() && dq[1][j].back().second > dp[i][j][k]) dq[1][j].pop_back();
                    while (dq[0][j].size() && dq[0][j].back().second > dp[i][j][k - 1]) dq[0][j].pop_back();
                    dq[1][j].push_back(make_pair(i, dp[i][j][k]));
                    dq[0][j].push_back(make_pair(i, dp[i][j][k - 1]));
                }
            }
        }
        // for(int i=0;i<26;i++){
        //     for(int j=1;j<=K;j++){
        //         printf("%d ",dp[n-1][i][j]);
        //     }
        //     puts("");
        // }

        int res = 1e9 + 9;
        for (int i = 0; i < 26; i++)
            for (int j = 1; j <= K; j++)
                res = min(res, dp[n - 1][i][j]);
        printf("%d\n", res);
    }
}
