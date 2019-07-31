#include <bits/stdc++.h>

typedef long long i64;
typedef long long LL;

const i64 MAXN = 1e18;
const i64 MAXNS3 = std::pow(MAXN, 1.0 / 3);
const i64 MAXNS4 = std::pow(MAXN, 1.0 / 4);

int primes[MAXNS3];
int pc;
bool visited[MAXNS3 + 1];

template <typename T>
void generatePrimeTable(T n) {
    
    for(T i = 2; i <= n; ++i) {
        
        if(!visited[i]) primes[pc++] = i;
        for(T j = 0; j < pc && i * primes[j] <= n; ++j) {
            
            visited[i * primes[j]] = true;
            if(!(i % primes[j])) break;
            
        }
        
    }
    
}

const int INF = 0x3F3F3F3F;

int calc(i64 x) {
    
    int result = INF;
    for(int i = 0; i < pc; ++i) {
        
        i64 p = primes[i];
        if(x < p * p) break;
        if(!(x % p)) {
            
            int c = 0;
            do { x /= p; ++c; } while(!(x % p));
            result = std::min(result, c);
            
        }
        
    }
    if(x != 1) result = 1;
    if(result == INF) result = 1;
    return result;
    
}

i64 sqr(i64 x) {

    i64 y = std::sqrt(x);
    while((y + 1) * (y + 1) <= x) ++y;
    return y;

}

int t;
i64 n;

int main() {
    
    generatePrimeTable(int(MAXNS3));
    
    std::set<i64> p3;
    std::vector<i64> p5(pc);
    for(int i = 0; i < pc; ++i) {
        
        i64 p = primes[i];
        i64 ppp = p * p * p;
        p3.insert(ppp);
        p5[i] = ppp * p * p;
        
    }
    
    std::scanf("%d", &t);
    for(int test = 0; test < t; ++test) {
        
        std::scanf("%lld", &n);
        //int ref = calc(n);
    
        int result = INF;
        if(n == 1) result = 0;
        else {
            
            for(int i = 0; i < pc; ++i) {
                
                i64 p = primes[i];
                if(!(n % p)) {
                    
                    int c = 0;
                    do { n /= p; ++c; } while(!(n % p));
                    result = std::min(result, c);
                    if(result == 1) break;
                    
                }
                if(n < p5[i]) break;
                
            }
            if(result != 1) {
                
                i64 sss = sqr(n);
                if(n != 1 && sss * sss == n) {
    
                    i64 ssss = sqr(sss);
                    if(ssss * ssss == sss) result = std::min(result, 4);
                    else result = std::min(result, 2);
    
                } else if(p3.count(n)) result = std::min(result, 3);
                else if(n != 1) result = std::min(result, 1);
                if(result == INF) result = 1;
    
            }
            
        }
        std::printf("%d\n", result);
        //if(result != ref) std::cerr << "WTF" << std::endl;
        
    }
    return 0;
    
}
