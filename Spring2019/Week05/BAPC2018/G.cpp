#include <bits/stdc++.h>

const int MAXN = 101000;

int n;
char str[MAXN * 2];
int sum[3][MAXN * 2];
int count[3];

int main() {
    
    std::scanf("%d%s", &n, str);
    std::memcpy(str + n, str, n);
    for(int i = 0; i < 3; ++i)
        sum[i][0] = 0;
    for(int i = 0; i < 2 * n; ++i) {

        int x = str[i] - 'A';
        for(int j = 0; j < 3; ++j)
            sum[j][i + 1] = sum[j][i];
        ++sum[x][i + 1];

    }
    for(int i = 0; i < 3; ++i)
        count[i] = sum[i][n];

    int result = n;
    for(int i = 0; i < n; ++i) {

        int a = i, b = a + count[0], c = b + count[1], d = c + count[2];
        result = std::min(result, n
            - (sum[0][b] - sum[0][a])
            - (sum[1][c] - sum[1][b])
            - (sum[2][d] - sum[2][c]));

    }
    for(int i = 0; i < n; ++i) {

        int a = i, b = a + count[0], c = b + count[2], d = c + count[1];
        result = std::min(result, n
            - (sum[0][b] - sum[0][a])
            - (sum[2][c] - sum[2][b])
            - (sum[1][d] - sum[1][c]));

    }

    std::printf("%d\n", result);

}