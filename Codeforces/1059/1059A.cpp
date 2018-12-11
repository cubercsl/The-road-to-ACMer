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
    int n, l, a;
    scanf("%d%d%d", &n, &l, &a);
    vector<int> vec;
    vec.push_back(0);
    for (int i = 0, t, l; i < n; i++)
    {
        scanf("%d%d", &t, &l);
        vec.push_back(t);
        vec.push_back(t + l);
    }
    vec.push_back(l);
    int ans = 0;
    for (int i = 0; i < vec.size(); i += 2) ans += (vec[i + 1] - vec[i]) / a;
    printf("%d\n", ans);
    return 0;
}