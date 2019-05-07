#include <bits/stdc++.h>

const int MAXS = 1000;

int t;
char str[MAXS];

int main() {

    std::scanf("%d", &t);
    for(int test = 0; test < t; ++test) {

        std::scanf("%s", str);
        std::string result;
        result += str[0];
        int n = std::strlen(str);
        for(int i = 1; i < n; ++i) {
            
            char c = str[i];
            if(c != 'a' && c != 'e' && c != 'i' && c != 'y' && c != 'o' && c != 'u')
                result += c;

        }
        std::puts(result.data());
        
    }

}
