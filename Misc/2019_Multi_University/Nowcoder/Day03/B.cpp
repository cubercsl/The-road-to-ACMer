#include <bits/stdc++.h>
 
 
typedef long long i64;
 
 
const int MAXN = 101000;
 
int n;
char s[MAXN];
int dp[MAXN];
std::map<int, int> m;
 
 
int main() {
     
    while(~std::scanf("%d%s", &n, s)) {
         
        int count[2] = {};
        for(int i = 0; i < n; ++i)
            ++count[s[i] - '0'];
         
         
        for (int i = -n; i <= n; i++)
            m[i] = -1;
        int cur = 0;
        m[0] = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
                cur++;
            else
                cur--;
            dp[i + 1] = cur;
            if (m[cur] == -1) m[cur] = i + 1;
        }
        int ans = 0;
        for (int i = 2; i <= n; i++)
        {
            int pos = m[dp[i]];
            if (~pos)
                ans = std::max(ans, i - pos);
        }
         
        std::printf("%d %d\n", ans, std::min(count[0], count[1]) * 2);
         
    }
     
}