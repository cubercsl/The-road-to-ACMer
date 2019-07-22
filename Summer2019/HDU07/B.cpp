#include<bits/stdc++.h>

typedef long long i64;

int t;
i64 n, k;

i64 countFull(int layer) {
    
    i64 result = 1;
    i64 x = 1;
    for(int i = 0; i < layer; ++i) {

        x *= k;
        result += x;

    }
    return result;

}
i64 calcFull(int layer) {

    if(k & 1) {
        
        i64 result = 0;
        for(int i = 0; i <= layer; ++i)
            result ^= countFull(i);
        return result;

    } else return countFull(layer);

}

i64 calc(i64 x) {

    if(x <= k + 1) return x ^ !(x & 1);
    int layer = 0;
    i64 y = x - 1;
    while(y > k) y = (y - 1) / k, ++layer;
    i64 left = y - 1, right = k - y;
    i64 result = x;
    if(left & 1) result ^= calcFull(layer);
    if(right & 1) result ^= calcFull(layer - 1);
    return result ^ calc(x - 1 - left * countFull(layer) - right * countFull(layer - 1));

}

/*i64 calc2(i64 x) {
    std::vector<int> vec(x, 1);
    for(int i = 0; i < x; ++i) {
        int j = i;
        while(j > 0) {
            j = (j - 1) / k;
            ++vec[j];

        }
    }
    i64 result = 0;
    for(int a : vec) result ^= a;
    return result;
}*/

int main() {
    
    std::scanf("%d", &t);
    for(int test = 0; test < t; ++test) {
        
        std::scanf("%lld%lld", &n, &k);
        i64 result = 0;
        if(k == 1) {
            
            switch(n % 4) {
            case 0: result = n; break;
            case 1: result = 1; break;
            case 2: result = n + 1; break;
            case 3: result = 0; break;
            }

        } else result = calc(n);
        std::printf("%lld\n", result);
        //std::printf("%lld\n", calc2(n));

    }

    return 0;
}