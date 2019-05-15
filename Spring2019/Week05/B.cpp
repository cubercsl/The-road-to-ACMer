#include <bits/stdc++.h>

const int MAXN = 200;

const int TABLE[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int n;
char str[100];
int arr[MAXN];

int getDay(int m) {

    int result = 0;
    for(int i = 0; i < m - 1; ++i)
        result += TABLE[i];
    return result;

}
int getDay(int m, int d) {

    return getDay(m) + d - 1;

}
int getMonth(int d) {

    int result = 1;
    int sum = TABLE[0] - 1;
    while(sum  < d) sum += TABLE[result], ++result;
    return result;

}

int main() {

    std::scanf("%d", &n);
    int d1027 = getDay(10, 29);
    for(int i = 0; i < n; ++i) {

        int m, d;
        std::scanf("%s %d-%d", str, &m, &d);
        arr[i] = (getDay(m, d) - d1027 + 365) % 365;

    }
    std::sort(arr, arr + n);
    int result = (arr[0] - 1 + 365) % 365;
    if(n > 1) {

        int maxd = arr[0] - arr[n - 1] + 365;
        for(int i = 0; i < n - 1; ++i) {
            
            int d = arr[i + 1] - arr[i];
            if(maxd >= d) continue;
            result = arr[i + 1] - 1;
            maxd = d;
            
        }

    }
    result = (result + d1027) % 365;
    int m = getMonth(result);
    int d = result - getDay(m) + 1;
    std::printf("%02d-%02d\n", m, d);

}