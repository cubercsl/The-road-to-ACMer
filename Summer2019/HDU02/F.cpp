#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const int MOD = 1000000007;

/*const int MAXN = 1000;
long long f[MAXN][MAXN];
bool visited[MAXN][MAXN];

long long calc(int n, int m, int x, int y) {

    if(visited[x][y]) return f[x][y];
    if(x == 1) {
        
        if(y == 1 || y == 2) f[x][y] = 1;
        else f[x][y] = (calc(n, m, x, y - 1) + calc(n, m, x, y - 2) * 2) % MOD;

    } else {

        f[x][y] = 0;
        for(int i = y; i <= y + n - 1; ++i)
            f[x][y] = (f[x][y] + calc(n, m, x - 1, i)) % MOD;

    }
    visited[x][y] = true;
    return f[x][y];

}
int calc(int n, int m) { return calc(n, m, m, 1); }*/

i64 pow64(i64 a, i64 b) {

    if(a == 1 || !b) return 1;
    i64 result = 1;
    while(b) {

        if(b & 1) result = result * a % MOD;
        a = a * a % MOD;
        b >>= 1;

    }
    return result;

}

i64 inv64(i64 x) {

    return pow64(x, MOD - 2);

}

const i64 inv3 = inv64(3);

int main() {

    /*for(int i = 1; i <= 10; ++i) {
        
        for(int j = 1; j <= 10; ++j) {
            
            std::memset(visited, 0, sizeof(visited));
            std::cout << std::setw(12) << calc(i, j);

        }
        std::cout << std::endl;

    }*/

    int t;
    std::scanf("%d", &t);
    for(int test = 0; test < t; ++test) {
        
        i64 n, m;
        std::scanf("%lld%lld", &n, &m);
        if(n == 1 || m == 1) std::puts("1");
        else {
            
            i64 result = (2 * pow64((pow64(2, n) + MOD - 1) % MOD, m - 1) % MOD + (n & 1)) % MOD * inv3 % MOD;
            std::printf("%lld\n", result);

        }

    }

}