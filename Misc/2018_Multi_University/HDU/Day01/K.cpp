#include <bits/stdc++.h>
using namespace std;

struct Time
{
    int t;
    Time(int h, int m) { t = h * 60 + m; }
    void out()
    {
        t = (t + 1440 * 2) % 1440;
        printf("%02d:%02d\n", t / 60, t % 60);
    }
};

char buf[10];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        Time t(a, b);
        scanf("%s", buf);
        string ss = (buf + 3);
        double c = stod(ss);
        int x = round((c - 8) * 60);
        // cerr << x << endl;
        t.t += x;
        t.out();
    }
}