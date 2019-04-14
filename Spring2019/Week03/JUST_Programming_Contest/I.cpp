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

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        vector<long long> a(n);
        for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
        sort(a.begin(), a.end());
        bool zero = 0;
        for (int i = 0; i < n; i++)
            if (a[i] == 0)
            {
                zero = true;
                break;
            }
            else if (a[i] < 0 && k)
                a[i] = -a[i], k--;
            else
                break;
        sort(a.begin(), a.end());
        long long sum = 0;
        if (zero)
            sum = accumulate(a.begin(), a.end(), 0LL);
        else if (k & 1)
        {
            a[0] = -a[0];
            sum = accumulate(a.begin(), a.end(), 0LL);
        }
        else
            sum = accumulate(a.begin(), a.end(), 0LL);
        printf("%lld\n", sum);
    }
    return 0;
}