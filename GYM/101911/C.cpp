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

const int N = 1 << 18;
int a[N];
typedef long long ll;

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    int d = 0;
    for (int i = 0; i < n; i++) d = gcd(a[i], d);
    for (int i = 0; i < n; i++) a[i] /= d;
    for (int i = 0; i < n; i++)
        if ((a[i] & (a[i] - 1))) return puts("-1"), 0;
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < n; i++) q.push(__lg(a[i]));
    int ans = 0;
    while (q.size() > 1)
    {
        ll a = q.top();
        q.pop();
        ll b = q.top();
        q.pop();
        // dbg(a, b);
        if (a == b)
            q.push(a + 1);
        else
        {
            ans++;
            q.push(b);
            q.push(a + 1);
        }
    }
    printf("%d\n", ans);
    return 0;
}