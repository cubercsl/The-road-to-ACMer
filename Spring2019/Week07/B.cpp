#include <bits/stdc++.h>
using namespace std;

struct Point
{
    double x, y;
    Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}
};
typedef Point Vector;
Vector operator+(Vector A, Vector B) { return Vector(A.x + B.x, A.y + B.y); }
Vector operator-(Point A, Point B) { return Vector(A.x - B.x, A.y - B.y); }
Vector operator*(Vector A, double p) { return Vector(A.x * p, A.y * p); }
Vector operator/(Vector A, double p) { return Vector(A.x / p, A.y / p); }
const double eps = 1e-10;
double dcmp(double x)
{
    if (fabs(x) < eps)
        return 0;
    else
        return x < 0 ? -1 : 1;
}
double Dot(Vector A, Vector B) { return A.x * B.x + A.y * B.y; }
double Length(Vector A) { return sqrt(Dot(A, A)); }
double Angle(Vector A, Vector B) { return acos(Dot(A, B) / Length(A) / Length(B)); }
double Cross(Vector A, Vector B) { return A.x * B.y - A.y * B.x; }
double Area2(Point A, Point B, Point C) { return Cross(B - A, C - A); }
double DistanceToLine(Point P, Point A, Point B)
{
    Vector v1 = B - A, v2 = P - A;
    return fabs(Cross(v1, v2)) / Length(v1);
}

int main()
{
    int x, y, r;
    scanf("%d%d", &x, &y);
    Point s(x, y);
    scanf("%d%d", &x, &y);
    Point t(x, y);
    scanf("%*d%*d%*d");
    scanf("%d%d%d", &x, &y, &r);
    Point o(x, y);
    double d = DistanceToLine(o, s, t);
    if (dcmp(d - r) > 0)
        printf("%.10f\n", Length(t - s));
    else
    {
        double a = Length(s - o);
        double b = Length(t - o);
        double c = Length(t - s);
        double th1 = acos(double(r) / a);
        double th2 = acos(double(r) / b);
        double th3 = acos((a * a + b * b - c * c) / (2 * a * b));
        double th = th3 - th1 - th2;
        if (dcmp(th) > 0)
        {
            double ans = a * sin(th1) + b * sin(th2) + r * th;
            printf("%.10f\n", ans);
        }
        else
            printf("%.10f\n", Length(t - s));
    }
}