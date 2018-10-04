#include <bits/stdc++.h>
using namespace std;

const int N = 64;
long long f[N];

int main()
{
    int n, d;
    scanf("%d%d", &n, &d);
    for (int i = 0; i <= d; i++) f[i] = i;
    for (int i = d + 1; i < N; i++) f[i] = f[i - 1] + f[i - d - 1] + 1;
    printf("%lld\n", ((1LL << (n - 1)) - 1 - f[n - d - 1]));
}