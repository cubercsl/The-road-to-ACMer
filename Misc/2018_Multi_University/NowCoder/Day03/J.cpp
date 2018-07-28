#include <bits/stdc++.h>
using namespace std;

typedef long double DB;
const DB eps = 1e-12;
struct Point
{
    DB x, y;
    Point(DB x = 0, DB y = 0) : x(x), y(y) {}
    void input() { scanf("%Lf%Lf", &x, &y); }
};
typedef Point Vector;
struct Circle
{
    Point c;
    DB r;
    Circle() {}
    Circle(Point c, DB r) : c(c), r(r) {}
};
int dcmp(DB x)
{
    if (x < -eps) return -1;
    if (x > eps) return 1;
    return 0;
}
template <class T>
T sqr(T x) { return x * x; }
Vector operator+(Vector A, Vector B) { return Vector(A.x + B.x, A.y + B.y); }
Vector operator-(Vector A, Vector B) { return Vector(A.x - B.x, A.y - B.y); }
Vector operator*(Vector A, DB p) { return Vector(A.x * p, A.y * p); }
Vector operator/(Vector A, DB p) { return Vector(A.x / p, A.y / p); }
bool operator<(const Point& a, const Point& b) { return a.x < b.x || (a.x == b.x && a.y < b.y); }
bool operator>=(const Point& a, const Point& b) { return a.x >= b.x && a.y >= b.y; }
bool operator<=(const Point& a, const Point& b) { return a.x <= b.x && a.y <= b.y; }
bool operator==(const Point& a, const Point& b)
{
    return dcmp(a.x - b.x) == 0 && dcmp(a.y - b.y) == 0;
}
DB Dot(Vector A, Vector B) { return A.x * B.x + A.y * B.y; }
DB Length(Vector A) { return sqrt(Dot(A, A)); }
DB Cross(Vector A, Vector B) { return A.x * B.y - A.y * B.x; }
DB TriAngleCircleInsection(Circle C, Point A, Point B)
{
    Vector OA = A - C.c, OB = B - C.c;
    Vector BA = A - B, BC = C.c - B;
    Vector AB = B - A, AC = C.c - A;
    DB DOA = Length(OA), DOB = Length(OB), DAB = Length(AB), r = C.r;
    if (dcmp(Cross(OA, OB)) == 0) return 0;
    if (dcmp(DOA - C.r) < 0 && dcmp(DOB - C.r) < 0)
        return Cross(OA, OB) * 0.5;
    else if (DOB < r && DOA >= r)
    {
        DB x = (Dot(BA, BC) + sqrt(r * r * DAB * DAB - Cross(BA, BC) * Cross(BA, BC))) / DAB;
        DB TS = Cross(OA, OB) * 0.5;
        return asin(TS * (1 - x / DAB) * 2 / r / DOA) * r * r * 0.5 + TS * x / DAB;
    }
    else if (DOB >= r && DOA < r)
    {
        DB y = (Dot(AB, AC) + sqrt(r * r * DAB * DAB - Cross(AB, AC) * Cross(AB, AC))) / DAB;
        DB TS = Cross(OA, OB) * 0.5;
        return asin(TS * (1 - y / DAB) * 2 / r / DOB) * r * r * 0.5 + TS * y / DAB;
    }
    else if (fabs(Cross(OA, OB)) >= r * DAB || Dot(AB, AC) <= 0 || Dot(BA, BC) <= 0)
    {
        if (Dot(OA, OB) < 0)
        {
            if (Cross(OA, OB) < 0)
                return (-acos(-1.0) - asin(Cross(OA, OB) / DOA / DOB)) * r * r * 0.5;
            else
                return (acos(-1.0) - asin(Cross(OA, OB) / DOA / DOB)) * r * r * 0.5;
        }
        else
            return asin(Cross(OA, OB) / DOA / DOB) * r * r * 0.5;
    }
    else
    {
        DB x = (Dot(BA, BC) + sqrt(r * r * DAB * DAB - Cross(BA, BC) * Cross(BA, BC))) / DAB;
        DB y = (Dot(AB, AC) + sqrt(r * r * DAB * DAB - Cross(AB, AC) * Cross(AB, AC))) / DAB;
        DB TS = Cross(OA, OB) * 0.5;
        return (asin(TS * (1 - x / DAB) * 2 / r / DOA) + asin(TS * (1 - y / DAB) * 2 / r / DOB)) * r * r * 0.5 + TS * ((x + y) / DAB - 1);
    }
}
Point P[666], A, B;
int main()
{
    int n, m;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) P[i].input();
    P[n + 1] = P[0];
    scanf("%d", &m);
    for (int i = 0, x, y, p, q; i < m; i++)
    {
        scanf("%d%d%d%d", &x, &y, &p, &q);
        Point o(x, y);
        DB L = 0, R = 1e12;
        DB tmp = 0.0;
        for (int j = 1; j < n - 1; j++)
            tmp += Cross(P[j] - P[0], P[j + 1] - P[0]);
        tmp = fabs(tmp) / 2;
        for (int i = 0; i < 200; i++)
        {
            DB r = (L + R) / 2;
            Circle C(o, r);
            DB ans = 0;
            for (int j = 0; j < n; j++)
                ans += TriAngleCircleInsection(C, P[j], P[j + 1]);
            ans = fabs(ans);
            if (ans * q > tmp * (q - p))
                R = r;
            else
                L = r;
        }
        printf("%.10Lf\n", L);
    }
}