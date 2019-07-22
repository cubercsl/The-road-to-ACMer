#include <bits/stdc++.h>

const int MAXN = 2000;

int t;
int arr[MAXN];

int main() {

    std::scanf("%d", &t);
    int result = 0;
    for(int i = 0; i < t; ++i)
        std::scanf("%d", &arr[i]), result += arr[i] <= 35;

    std::printf("%d\n", result);

}