#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 18 | 1;
char buf[N];
bool s[N];
int ans;

inline bool check(int n, bool* s)
{
    for (int i = 0; i < n; i++)
        if (s[i] == 1) return true;
    return false;
}

void dfs(int n, bool* s)
{
    if (n == 1)
    {
        if (s[0] == 1) ++ans;
        return;
    }
    bool ss[N];
    for (int i = 0; i < n; i += 2) ss[i >> 1] = s[i] & s[i + 1];
    if (check(n >> 1, ss)) dfs(n >> 1, ss);
    for (int i = 0; i < n; i += 2) ss[i >> 1] = s[i] | s[i + 1];
    if (check(n >> 1, ss)) dfs(n >> 1, ss);
    for (int i = 0; i < n; i += 2) ss[i >> 1] = s[i] ^ s[i + 1];
    if (check(n >> 1, ss)) dfs(n >> 1, ss);
}

int main()
{
    int n;
    scanf("%d", &n);
    scanf("%s", buf);
    for (int i = 0; i < (1 << n); i++) s[i] = buf[i] == '1';
    dfs(1 << n, s);
    printf("%d\n", ans);
    return 0;
}