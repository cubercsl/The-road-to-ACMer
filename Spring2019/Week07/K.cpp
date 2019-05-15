
#include <bits/stdc++.h>

using ll = long long;

const int MAXN = 2000;
const int MAXG = 2000;

int n, g;
int arr[MAXN];
ll dp[MAXG];

int main() {

    std::scanf("%d%d", &n, &g);
    for(int i = 0; i < n; ++i)
        std::scanf("%d", &arr[i]);
    
    dp[0] = 1;
    for(int i = 1; i < MAXG; ++i)
        dp[i] = 0;

    for(int i = 0; i < n; ++i) {

        for(int j = MAXG - arr[i] - 1; j >= 0; --j) {
            
            if(!dp[j]) continue;
            dp[j + arr[i]] |= dp[j] << 1;

        }

    }

    double result = -1e5;
    for(int i = 1; i <= n; ++i) {

        int minX = g - 10;
        int maxX = g + (i - 1) * 5;
        for(int j = maxX; j >= minX; --j) {

            if(dp[j] & (ll(1) << i)) {
                
                result = std::max(result, (j - minX) * 5 / double(maxX - minX));
                break;

            }

        }

    }
    if(result < -1) std::printf("impossible");
    else std::printf("%.10f\n", result);

}
