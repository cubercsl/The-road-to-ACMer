#include <bits/stdc++.h>


const int MAXN = 301000;
char str[MAXN];

int rev(char c) {

    int result = 0;
    for(int i = 0; i < 8; ++i)
        if(c & (1 << i)) result |= 1 << (7 - i);
    return result;

}

int main() {
    
    std::fgets(str, sizeof(str), stdin);
    int n = std::strlen(str);

    //bool first = true;
    for(int i = 0; i < n / 3; ++i) {

        int x = rev(str[i * 3]) * 256 * 256 + rev(str[i * 3 + 1]) * 256 + rev(str[i * 3 + 2]);
        //if(first) first = false;
        //else std::putchar(' ');
        int a = x / (64 * 64 * 64);
        int b = x / (64 * 64) % 64;
        int c = x / 64 % 64;
        int d = x % 64;
        std::printf("%d %d %d %d ", a, b, c, d);
        
    }
    //std::putchar('\n');

}