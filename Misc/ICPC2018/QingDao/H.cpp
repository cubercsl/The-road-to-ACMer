#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 17;
char s[N];
typedef long long ll;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%s", s);
        ll ans = 0;
        int n = strlen(s);
        for (int i = 0; i < n; i++) ans += 1LL * (i + 1) * (n - i);
        for (int i = 0; s[i]; i++)
        {
            if (s[i] == '0') ans += n - i;
            if (i && (s[i] == s[i - 1])) ans += 1LL * i * (n - i);
        }
        printf("%lld\n", ans);
    }
}
