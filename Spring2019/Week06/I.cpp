#include <bits/stdc++.h>

const int MAXS = 11000;

int t;
char a[MAXS], b[MAXS];

int main() {

    std::scanf("%d", &t);
    for(int test = 0; test < t; ++test) {

        std::scanf("%s%s", a, b);
        int na = std::strlen(a), nb = std::strlen(b);
        int ca = -1, cb = 0;
        for(int i = 0; i < na; ++i)
            ca += a[i] - '0';
        for(int i = 0; i < nb; ++i)
            cb += b[i] - '0';
        int xa = ca % 3 == 1, xb = cb % 3 == 1;
        int x = xa ^ xb;
        std::puts(x ? "1" : "0");

    }

}
