#include <bits/stdc++.h>

using ll = long long;

const int MAXS = 2000010;

int t;
char a[MAXS], b[MAXS];

namespace CSL
{
const int N = 2000005;
char s[N], str[N << 1];
int p[N << 1];
void Manacher(char s[], int& n)
{
    str[0] = '$', str[1] = '#';
    for (int i = 0; i < n; i++) str[(i << 1) + 2] = s[i], str[(i << 1) + 3] = '#';
    n = 2 * n + 2;
    str[n] = 0;
    int mx = 0, id;
    for (int i = 1; i < n; i++)
    {
        p[i] = mx > i ? std::min(p[2 * id - i], mx - i) : 1;
        while (str[i - p[i]] == str[i + p[i]]) p[i]++;
        if (p[i] + i > mx) mx = p[i] + i, id = i;
    }
}
long long solve(char s[])
{
    int n = strlen(s);
    Manacher(s, n);
    long long ans = 0;
    for (int i = 0; i < n; i++) ans += p[i] / 2;
    return ans;
}
} // namespace CSL

int main()
{

    std::scanf("%d", &t);
    for (int test = 0; test < t; ++test)
    {

        std::scanf("%s%s", a, b);
        int n = std::strlen(a);

        int lu = 0;
        for (; lu < n && a[lu] == b[lu]; ++lu)
            ;
        if (lu == n)
        {
            long long ans = CSL::solve(a);
            printf("%lld\n", ans);
            // Same string
        }
        else
        {

            int ru = n - 1;
            for (; a[ru] == b[ru]; --ru)
                ;
            int nu = ru - lu + 1;
            bool ok = true;
            for (int i = 0; i < nu; ++i)
                if (a[lu + i] != b[ru - i])
                {
                    ok = false;
                    break;
                }
            if (!ok)
                std::puts("0");
            else
            {
                int result = 1;
                while (lu - result >= 0 && ru + result < n)
                {

                    if (a[lu - result] != a[ru + result]) break;
                    ++result;
                }
                std::printf("%d\n", result);
            }
        }
    }
}
