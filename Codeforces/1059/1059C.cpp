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
    while (cin >> n)
    {
        vector<int> a(n);
        iota(a.begin(), a.end(), 1);
        vector<int> ans;
        do
        {
            vector<int> tmp;
            for (int i = 0; i < n; i++)
            {
                int x = 0;
                for (int j = i; j < n; j++) x = gcd(x, a[j]);
                tmp.push_back(x);
            }
            ans = max(ans, tmp);
        } while (next_permutation(a.begin(), a.end()));
        for(auto& t: ans) printf("%d ", t);
        puts("");
    }
    return 0;
}