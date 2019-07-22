#include<bits/stdc++.h>

const int MAXN = 10001000;

int t;
int n;

int calc(int x) {

    return (x + 1) / 2 + 1;

}

int main() {
    
    std::scanf("%d", &t);
    for(int test = 0; test < t; ++test) {
        
        std::scanf("%d", &n);
        std::printf("%d\n", calc(n));

    }

    return 0;
}