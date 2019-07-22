#include <iostream>

using i64 = long long;


int t;
i64 n, m;


int main() {

    std::scanf("%d", &t);
    for(int test = 0; test < t; ++test) {

        std::scanf("%lld%lld", &n, &m);
        i64 limit = n * (n - 1) / 2;
        i64 result;
        if(m >= limit) result = limit * 2;
        else if(m < n - 1) {
            
            i64 x = n - m - 1;
            result = 2 * m * m + x * m * n + x * n * n;

        } else result = (2 * limit - m) * 2;
        std::printf("%lld\n", result);

    }

}