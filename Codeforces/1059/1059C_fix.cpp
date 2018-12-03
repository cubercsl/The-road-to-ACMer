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
    int n;
    scanf("%d", &n);
    vector<int> ans;
    int ls = n;
    for (int i = 0, m = n; n != 1; i++, m >>= 1)
    {
        int x = n + 1 >> 1;
        for (int j = 0; j < x; j++) ans.push_back(1 << i);
        n -= x;
        if(n == 1) break;
        if (m & 1)
        {
            int t = ls / m * 2;
            while (ls % t) ls--;
            m = ls / t * 2;
        }
    }
    ans.push_back(ls);
    for(auto& t : ans) printf("%d ", t);
    return 0;
}