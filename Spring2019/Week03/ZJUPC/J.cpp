#include <bits/stdc++.h>

const int MAXN = 101000;

int t;
int n;

int main() {

    std::scanf("%d", &t);
    for(int test = 0; test < t; ++test) {

        std::scanf("%d", &n);
        if(n & 1) {
            
            std::printf("%d %d\n", 9, 9 + n);

        } else {
            
            std::printf("%d %d\n", 4, 4 + n);

        }

    }

}
