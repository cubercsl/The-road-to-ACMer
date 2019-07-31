#include <bits/stdc++.h>

typedef long long i64;
typedef unsigned long long u64;

const int MAXN = 101000;

int t, n, k;

int main() {
    
    std::scanf("%d", &t);
    for(int test = 0; test < t; ++test) {
        
        std::scanf("%d%d", &n, &k);
        if(n % k) std::puts("no");
        else if(n / k == 1) {
            
            if(k == 1) {
                
                std::puts("yes");
                for(int i = 0; i < n; ++i)
                    std::printf("%d%c", i + 1, " \n"[i == n - 1]);
                
            } else std::puts("no");
            
        } else if((n / k) & 1) {
            
            if(k & 1) {
                
                std::puts("yes");
                for(int i = 0; i < k; ++i) {
                    
                    int a = i + 1, b = ((k + 1) / 2 + i) % k + k + 1, c = 3 * (3 * k + 1) / 2 - a - b;
                    std::printf("%d %d %d", a, b, c);
                    int base = 3 * k + 1;
                    int nn = n - 3 * k;
                    int cc = nn / k / 2;
                    for(int j = 0; j < cc; ++j)
                        std::printf(" %d", i * cc + j + base);
                    for(int j = 0; j < cc; ++j)
                        std::printf(" %d", nn - (i + 1) * cc + j + base);
                    std::putchar('\n');
                    
                }
                
            } else std::puts("no");
            
        } else {
            
            std::puts("yes");
            int c = n / k / 2;
            for(int i = 0; i < k; ++i) {
                
                for(int j = 0; j < c; ++j)
                    std::printf("%d ", i * c + j + 1);
                for(int j = 0; j < c; ++j)
                    std::printf("%d%c", n - (i + 1) * c + j + 1, " \n"[j == c - 1]);
                
            }
            
        }
        
    }
    
}
