#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll a[3], b[3], x[3], y[3];

int main(int argc, char* argv[])
{
    registerTestlibCmd(argc, argv);
    int T = inf.readInt();
    while (T--)
    {
        for (int i = 0; i < 3; i++)
            a[i] = inf.readInt(-10000, 10000), b[i] = inf.readInt(-10000, 10000);
        for (int i = 0; i < 3; i++) x[i] = ouf.readLong(ll(-1e18), ll(1e18));
        for (int i = 0; i < 3; i++)
            y[i] = x[i] * x[i] + a[i] * x[i] + b[i];
        // printf("%lld %lld %lld\n", y[0], y[1], y[2]);
        if (y[0] == y[1] || y[1] == y[2] || y[0] == y[2]) continue;
        println(x[0], x[1], x[2]);
        println(a[0], b[0], a[1], b[1], a[2], b[2]);
        quitf(_wa, "%lld %lld %lld\n", y[0], y[1], y[2]);
    }
    quitf(_ok, "Ok");
}