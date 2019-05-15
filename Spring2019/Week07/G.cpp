#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-10;
const double pi = acos(-1.0);
const double c0 = 299792.458;

struct Point
{
    double x, y, z;
    Point(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}
};

typedef Point Vector;
Vector operator+(Vector A, Vector B) { return Vector(A.x + B.x, A.y + B.y, A.z + B.z); }
Vector operator-(Point A, Point B) { return Vector(A.x - B.x, A.y - B.y, A.z - B.z); }
double Dot(Vector A, Vector B) { return A.x * B.x + A.y * B.y + A.z * B.z; }
double Length(Vector A) { return sqrt(Dot(A, A)); }
int dcmp(double x)
{
    if (fabs(x) < eps) return 0;
    return x < 0 ? -1 : 1;
}

inline void DegrtoRad(double& deg) { deg = deg / 180 * pi; }

Point getPerson()
{
    const static double r = 6371;
    double u, v;
    scanf("%lf%lf", &u, &v);
    DegrtoRad(u), DegrtoRad(v);
    return Point(r * cos(v) * sin(u), -r * cos(v) * cos(u), r * sin(v));
}

Point getSate()
{
    double u, v, r, t;
    scanf("%lf%lf%lf%lf", &u, &v, &r, &t);
    DegrtoRad(u), DegrtoRad(v);
    t *= 2 * pi;
    return Point(
        r * sin(t) * cos(v) * cos(u) + r * cos(t) * sin(u),
        r * sin(t) * cos(v) * sin(u) - r * cos(t) * cos(u),
        r * sin(t) * sin(v));
}

int main()
{
    int T;
    scanf("%d", &T);
    Point A = getPerson();
    while (T--)
    {
        Point B = getSate();
        if (dcmp(Dot(A, B - A)) < 0)
            puts("no signal");
        else
            printf("%.10f\n", Length(B - A) / c0);
    }
    return 0;
}
