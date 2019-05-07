#include <bits/stdc++.h>

int v;

int main() {
    
    std::scanf("%d", &v);
    int result = 1000000000;
    int maxa = std::sqrt(v);
    for(int a = 1; a <= maxa; ++a) {

        if(v % a) continue;
        int bc = v / a;
        int maxb = std::sqrt(bc);
        for(int b = 1; b <= maxb; ++b) {

            if(bc % b) continue;
            int c = bc / b;
            int cur = 2 * (a * b + a * c + bc);
            result = std::min(result, cur);
            
        }

    }
    std::printf("%d\n", result);

}