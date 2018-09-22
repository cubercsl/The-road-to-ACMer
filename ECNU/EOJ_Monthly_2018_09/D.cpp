#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
bool isp(ll x)
{
    for (ll i = 2; i * i <= x; i++)
        if (x % i == 0) return false;
    return x != 1;
}

void quitf()
{
    puts("Impossible");
    exit(0);
}

int main()
{
    int n;
    scanf("%d", &n);
    if (n > 3) quitf();
    vector<int> a(n);
    for (auto& t : a) scanf("%d", &t);
    if (n == 1)
    {
        if (a[0] == 0) return puts("2"), 0;
        if (isp(a[0])) return printf("%d\n", a[0]), 0;
        quitf();
    }
    if (n == 2)
    {
        if (a[0] == 0 && a[1] == 0) return puts("2 3"), 0;
        if (a[0] == 0)
        {
            if (isp(a[1]))
            {
                if (isp(a[1] + 2))
                    return printf("2 %d\n", a[1]), 0;
                if (isp(a[1] + 3))
                    return printf("3 %d\n", a[1]), 0;

                quitf();
            }
            else
                quitf();
        }

        if (a[1] == 0)
        {
            if (isp(a[0]))
            {
                if (isp(a[0] + 2))
                    return printf("%d 2\n", a[0]), 0;
                if (isp(a[0] + 3))
                    return printf("%d 3\n", a[0]), 0;
                quitf();
            }
            else
                quitf();
        }
        if (isp(a[0]) && isp(a[1]) && isp(a[0] + a[1]))
            return printf("%d %d\n", a[0], a[1]), 0;
        quitf();
    }
    if (n == 3)
    {
        if (a[0] == 0) a[0] = 2;
        if (a[2] == 0) a[2] = 2;
        if (a[0] != 2 || a[2] != 2) quitf();
        if (a[1] != 0)
        {
            if (!isp(a[1])) quitf();
            if (!isp(a[1] + 2) || !isp(a[1] + 4)) quitf();
        }
        else
            a[1] = 3;
        printf("%d %d %d\n", a[0], a[1], a[2]);
    }
}