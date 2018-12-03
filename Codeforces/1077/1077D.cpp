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

const int N = 1 << 17;
pair<int, int> cnt[N];
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < N; i++) cnt[i].second = i;
    for (int i = 0, x; i < n; i++)
    {
        scanf("%d", &x);
        cnt[x].first++;
    }
    sort(cnt, cnt + N, greater<pair<int, int>>());
    for (int i = 0; i < k; i++) printf("%d ", cnt[i].second);
    return 0;
}