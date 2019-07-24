#include <cassert>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cstdio>

#include <algorithm>
#include <bitset>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

//#include <random>
//#include <unordered_map>


typedef long long i64;

const int MOD = 998244353;

i64 pow64(i64 a, i64 b) {
    
    if(!b) return 1;
    i64 result = 1;
    while(b) {
        
        if(b & 1) result = result * a % MOD;
        a = a * a % MOD;
        b >>= 1;
        
    }
    return result;
    
}
i64 inv64(i64 a) { return pow64(a, MOD - 2); }

const int MAXN = 3000;

int n;
int arr[MAXN + 1];

int main() {
    
    arr[0] = 0;
    int inv9 = inv64(9);
    int x = 0;
    for(int i = 1; i <= MAXN; ++i) {
        
        arr[i] = i64(x) * inv9 % MOD;
        x += i * 2 + 1;
        
    }
    
    while(~std::scanf("%d", &n)) {
        
        std::printf("%d\n", arr[n]);
        
    }
    
}