#include<bits/stdc++.h>

const int MAXN = 10001000;

std::vector<bool> vec1;

int t;
int n;

int main() {
    
    vec1.push_back(0);
    vec1.push_back(1);
    vec1.push_back(1);
    bool current = 0;
    for(int i = 2; vec1.size() < MAXN; ++i, current = !current) {

        for(int j = 0; j < vec1[i] + 1; ++j)
            vec1.push_back(current);

    }

    std::scanf("%d", &t);
    for(int test = 0; test < t; ++test) {
        
        std::scanf("%d", &n);
        std::printf("%d\n", vec1[n - 1] + 1);

    }

    return 0;
}