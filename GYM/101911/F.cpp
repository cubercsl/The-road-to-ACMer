#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define dbg(args...)                             \
    do                                           \
    {                                            \
        cout << "\033[32;1m" << #args << " -> "; \
        err(args);                               \
    } while (0)
#else
#define dbg(...)
#endif
void err()
{
    cout << "\033[39;0m" << endl;
}
template <template <typename...> class T, typename t, typename... Args>
void err(T<t> a, Args... args)
{
    for (auto x : a) cout << x << ' ';
    err(args...);
}
template <typename T, typename... Args>
void err(T a, Args... args)
{
    cout << a << ' ';
    err(args...);
}
/****************************************************************************************************/

const int N = 1 << 20;
int ans[N];
int cnt[30];

int main()
{
    for (int i = 0; i < N; i++)
    {
        vector<int> d(6);
        for (int j = 0, x = i; j < 6; j++, x /= 10)
            d[j] = x % 10;
        int a = 0, b = 0;
        for (int j = 0; j < 3; j++) a += d[j];
        for (int j = 3; j < 6; j++) b += d[j];
        int sum = abs(a - b);
        int tmp = 0;
        for (int j = sum - 1; ~j; j--) tmp += cnt[j];
        ans[i] = tmp;
        cnt[sum]++;
    }
    int n;
    scanf("%d", &n);
    for (int i = 0, x; i < n; i++)
    {
        scanf("%d", &x);
        printf("%d\n", ans[x]);
    }
    return 0;
}