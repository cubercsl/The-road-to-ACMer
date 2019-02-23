#include <bits/stdc++.h>
using namespace std;

const int maxn = 1 << 20;
char s[maxn];

int main()
{

    int n, q, m;
    scanf("%s", s + 1);
    n = strlen(s + 1);
    scanf("%d", &q);
    while (q--)
    {
        scanf("%d", &m);
        vector<int> r(m, -1);
        int now = 0, pw = 1;
        r[0] = n + 1;
        for (int i = n; i; --i)
        {
            now = (now + 1LL * pw * (s[i] - '0')) % m, pw = pw * 10 % m;
            if (~r[now])
            {
                printf("%d %d\n", i, r[now] - 1);
                break;
            }
            r[now] = i;
        }
    }
}