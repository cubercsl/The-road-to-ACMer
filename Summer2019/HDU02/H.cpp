#include <bits/stdc++.h>

using i64 = long long;

const int MAXN = 110;

int t;
int n, m;

int arr[MAXN][MAXN];

int count[MAXN * MAXN];

int main() {

    std::scanf("%d", &t);
    for(int test = 0; test < t; ++test) {

        std::scanf("%d%d", &n, &m);

        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                std::scanf("%d", &arr[i][j]);

        i64 count = 0;

        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)

        double result = count / double();

        std::printf("%.9f\n", result);

    }

}