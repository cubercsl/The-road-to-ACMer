#include <bits/stdc++.h>
using namespace std;

struct Point
{
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
};

typedef Point Vector;

//向量+向量=向量，点+向量=点
Vector operator+(Vector A, Vector B) { return Vector(A.x + B.x, A.y + B.y); }
//点-点=向量
Vector operator-(Point A, Point B) { return Vector(A.x - B.x, A.y - B.y); }
//向量*数=向量
Vector operator*(Vector A, double p) { return Vector(A.x * p, A.y * p); }
//向量/数=向量
Vector operator/(Vector A, double p) { return Vector(A.x / p, A.y / p); }

bool operator<(const Point& a, const Point& b)
{
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

const double eps = 1e-10;
double dcmp(double x)
{
    if (fabs(x) < eps)
        return 0;
    else
        return x < 0 ? -1 : 1;
}

bool operator==(const Point& a, const Point& b)
{
    return dcmp(a.x - b.x) == 0 && dcmp(a.y - b.y) == 0;
}

double Dot(Vector A, Vector B) { return A.x * B.x + A.y * B.y; }
double Length(Vector A) { return sqrt(Dot(A, A)); }
double Angle(Vector A, Vector B) { return acos(Dot(A, B) / Length(A) / Length(B)); }

double Cross(Vector A, Vector B) { return A.x * B.y - A.y * B.x; }
double Area2(Point A, Point B, Point C) { return Cross(B - A, C - A); }

Vector Rotate(Vector A, double rad)
{
    return Vector(A.x * cos(rad) - A.y * sin(rad),
                  A.x * sin(rad) + A.y * cos(rad));
}

//调用前请确保A不是零向量
Vector Normal(Vector A)
{
    double L = Length(A);
    return Vector(-A.y / L, A.x / L);
}

struct Line
{
    Point p;    //直线上任意一点
    Vector v;   //方向向量。它的左边就是对应的半平面
    double ang; //极角。即从x正半轴旋转到向量v所需要的角（弧度）
    Line() {}
    Line(Point p, Vector v) : p(p), v(v) { ang = atan2(v.y, v.x); }
    bool operator<(const Line& L) const // 排序用的比较运算符
    {
        return ang < L.ang;
    }
    Point point(double t) { return p + v * t; }
};

Point GetLineIntersection(const Line& a, const Line& b)
{
    Vector u = a.p - b.p;
    double t = Cross(b.v, u) / Cross(a.v, b.v);
    return a.p + a.v * t;
}

bool OnLeft(const Line& L, const Point& p)
{
    return Cross(L.v, p - L.p) > 0;
}

vector<Point> HalfplaneIntersection(vector<Line>& L)
{
    int n = L.size();
    sort(L.begin(), L.end()); // 按极角排序

    int first, last;    // 双端队列的第一个元素和最后一个元素的下标
    vector<Point> p(n); // p[i]为q[i]和q[i+1]的交点
    vector<Line> q(n);  // 双端队列
    vector<Point> ans;  // 结果

    q[first = last = 0] = L[0]; // 双端队列初始化为只有一个半平面L[0]
    for (int i = 1; i < n; i++)
    {
        while (first < last && !OnLeft(L[i], p[last - 1])) last--;
        while (first < last && !OnLeft(L[i], p[first])) first++;
        q[++last] = L[i];
        if (fabs(Cross(q[last].v, q[last - 1].v)) < eps)
        { // 两向量平行且同向，取内侧的一个
            last--;
            if (OnLeft(q[last], L[i].p)) q[last] = L[i];
        }
        if (first < last) p[last - 1] = GetLineIntersection(q[last - 1], q[last]);
    }
    while (first < last && !OnLeft(q[first], p[last - 1])) last--; // 删除无用平面
    if (last - first <= 1) return ans;                             // 空集
    p[last] = GetLineIntersection(q[last], q[first]);              // 计算首尾两个半平面的交点

    // 从deque复制到输出中
    for (int i = first; i <= last; i++) ans.push_back(p[i]);
    return ans;
}

vector<Point> new_poly(vector<Point> p, double r)
{
    vector<Line> lines;
    int n = p.size();
    p.push_back(p[0]);
    for (int i = 0; i < n; i++)
    {
        Vector v = Normal(p[i + 1] - p[i]) * r;
        lines.emplace_back(p[i] + v, p[i + 1] - p[i]);
    }
    return HalfplaneIntersection(lines);
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        double r;
        int n;
        scanf("%d%lf", &n, &r);
        vector<Point> p(n);
        for (auto& t : p) scanf("%lf%lf", &t.x, &t.y);
        reverse(p.begin(), p.end());
        vector<Point> poly = new_poly(p, r);
        n = poly.size();
        double ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
            {
                int l = j + 1, r = n - 1;
                for (;;)
                {
                    int m1 = (2 * l + r) / 3;
                    int m2 = (l + 2 * r) / 3;
                    if (fabs(Area2(poly[i], poly[j], poly[m1])) < fabs(Area2(poly[i], poly[j], poly[m2])))
                    {
                        if (m1 == l) break;
                        l = m1;
                    }
                    else
                    {
                        if (m2 == r) break;
                        r = m2;
                    }
                }
                for (int k = l; k <= r; k++) ans = max(ans, fabs(Area2(poly[i], poly[j], poly[k])));
            }
        printf("%.9f\n", ans);
    }
}