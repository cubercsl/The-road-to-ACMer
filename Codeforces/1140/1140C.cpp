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
    int n, k;
    scanf("%d%d", &n, &k);
    vector<pair<int, int>> vec;
    for (int i = 0, x, y; i < n; i++)
    {
        scanf("%d%d", &x, &y);
        vec.emplace_back(y, x);
    }
    sort(vec.begin(), vec.end(), greater<pair<int, int>>());
    priority_queue<int, vector<int>, greater<int>> q;
    long long sum = 0;
    long long ans = 0;
    for (int i = 0; i < n;)
    {
        int cur = vec[i].first;
        while (i < n && vec[i].first == cur)
        {
            q.push(vec[i].second), sum += vec[i].second;
            if (q.size() == k + 1) sum -= q.top(), q.pop();
            i++;
        }
        dbg(cur, sum);
        ans = max(ans, cur * sum);
    }
    printf("%lld\n", ans);
    return 0;
}