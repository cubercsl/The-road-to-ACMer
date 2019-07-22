#include <bits/stdc++.h>
using namespace std;
typedef double ld;

const ld eps = 1e-10;

int solve(ld a, ld b, ld c, ld& x1, ld& x2)
{
    if(fabs(a) < eps) {
        x1 = -c / b;
        return 1;
    }
    ld delt = b * b - 4 * a * c;
    if (fabs(delt) < eps)
    {
        x1 = -b / (2 * a);
        return 1;
    }
    if (delt < 0) return 0;
    x1 = (-b + sqrt(delt)) / (a * 2);
    x2 = (-b - sqrt(delt)) / (a * 2);
    if (x1 > x2)
        swap(x1, x2);
    return 2;
}

template <class T>
inline T sqr(T x) { return x * x; }

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T, kase = 0;
    cin >> T;
    while (T--)
    {
        ld r, h;
        ld x0, y0, z0;
        ld vx, vy, vz;
        cin >> r >> h;
        cin >> x0 >> y0 >> z0;
        cin >> vx >> vy >> vz;
        ld a = sqr(vz * r) - sqr(h) * (sqr(vx) + sqr(vy));
        ld b = -2 * (sqr(r) * (h - z0) * vz + sqr(h) * (x0 * vx + y0 * vy));
        ld c = sqr(r * (h - z0)) - sqr(h) * (sqr(x0) + sqr(y0));
        ld t1, t2;
        solve(a, b, c, t1, t2);
        cout << "Case " << ++kase << ": " << fixed << setprecision(10) << (double)t1 << endl;
    }
}