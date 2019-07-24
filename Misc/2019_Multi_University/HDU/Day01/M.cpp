#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sgn(x) ((x) == 0 ? 0 : ((x) < 0 ? -1 : 1))

struct Point {
  ll x, y;
  Point(ll x = 0, ll y = 0) : x(x), y(y) {}
  ll operator^(const Point& b) const { return x * b.y - y * b.x; }
};
typedef vector<Point> Polygon;
typedef Point Vector;
bool operator<(const Point& a, const Point& b) {
  return a.x < b.x || (a.x == b.x && a.y < b.y);
}
//向量+向量=向量，点+向量=点
Vector operator+(Vector A, Vector B) { return Vector(A.x + B.x, A.y + B.y); }
//点-点=向量
Vector operator-(Point A, Point B) { return Vector(A.x - B.x, A.y - B.y); }
//向量*数=向量
Vector operator*(Vector A, ll p) { return Vector(A.x * p, A.y * p); }
//向量/数=向量
Vector operator/(Vector A, ll p) { return Vector(A.x / p, A.y / p); }

ll Cross(Vector A, Vector B) { return A.x * B.y - A.y * B.x; }

ll dcmp(ll x) {
  if (x == 0)
    return 0;
  else
    return x < 0 ? -1 : 1;
}

bool operator==(const Point& a, const Point& b) {
  return dcmp(a.x - b.x) == 0 && dcmp(a.y - b.y) == 0;
}

/*
 * 基本运算：
 * 点积
 * 叉积
 * 向量旋转
 */
ll Dot(Vector A, Vector B) { return A.x * B.x + A.y * B.y; }
ll Length(Vector A) { return sqrt(Dot(A, A)); }
ll Angle(Vector A, Vector B) { return acos(Dot(A, B) / Length(A) / Length(B)); }

ll Area2(Point A, Point B, Point C) { return Cross(B - A, C - A); }

bool OnSegment(Point p, Point a1, Point a2) {
  return dcmp(Cross(a1 - p, a2 - p)) == 0 && dcmp(Dot(a1 - p, a2 - p)) < 0;
}

vector<Point> p[2];

Polygon ConvexHull(vector<Point> p) {
  sort(p.begin(), p.end());
  p.erase(unique(p.begin(), p.end()), p.end());
  int n = p.size(), m = 0;
  Polygon res(n + 1);
  for (int i = 0; i < n; i++) {
    while (m > 1 && Cross(res[m - 1] - res[m - 2], p[i] - res[m - 2]) <= 0) m--;
    res[m++] = p[i];
  }
  int k = m;
  for (int i = n - 2; i >= 0; i--) {
    while (m > k && Cross(res[m - 1] - res[m - 2], p[i] - res[m - 2]) <= 0) m--;
    res[m++] = p[i];
  }
  m -= n > 1;
  res.resize(m);
  return res;
}
//点在多边形内判定
int isPointInPolygon(Point p, Polygon poly) {
  int wn = 0;  //绕数
  int n = poly.size();
  for (int i = 0; i < n; i++) {
    if (OnSegment(p, poly[i], poly[(i + 1) % n])) return -1;  //边界上
    int k = dcmp(Cross(poly[(i + 1) % n] - poly[i], p - poly[i]));
    int d1 = dcmp(poly[i].y - p.y);
    int d2 = dcmp(poly[(i + 1) % n].y - p.y);
    if (k > 0 && d1 <= 0 && d2 > 0) wn++;
    if (k < 0 && d2 <= 0 && d1 > 0) wn--;
  }
  if (wn != 0) return 1;  //内部
  return 0;               //外部
}
struct line {
  Point s, e;
  line() {}
  line(Point ss, Point ee) { s = ss, e = ee; }
};

bool segxseg(line l1, line l2) {
  return max(l1.s.x, l1.e.x) >= min(l2.s.x, l2.e.x) &&
         max(l2.s.x, l2.e.x) >= min(l1.s.x, l1.e.x) &&
         max(l1.s.y, l1.e.y) >= min(l2.s.y, l2.e.y) &&
         max(l2.s.y, l2.e.y) >= min(l1.s.y, l1.e.y) &&
         sgn((l2.s - l1.e) ^ (l1.s - l1.e)) *
                 sgn((l2.e - l1.e) ^ (l1.s - l1.e)) <=
             0 &&
         sgn((l1.s - l2.e) ^ (l2.s - l2.e)) *
                 sgn((l1.e - l2.e) ^ (l2.s - l2.e)) <=
             0;
}

bool ok(Polygon po1, Polygon po2) {
  for (auto& v : po1)
    if (isPointInPolygon(v, po2) != 0) return false;
  for (auto& v : po2)
    if (isPointInPolygon(v, po1) != 0) return false;
  for (int i = 0; i < po1.size(); i++) {
    line l1(po1[i], po1[(i + 1) % po1.size()]);
    for (int j = 0; j < po2.size(); j++) {
      line l2(po2[j], po2[(j + 1) % po2.size()]);
      if (segxseg(l1, l2)) return false;
    }
  }
  return true;
}
bool solve(int n) {
  if (n <= 1) return true;
  return ok(ConvexHull(p[0]), ConvexHull(p[1]));
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    p[0].clear();
    p[1].clear();

    int n;
    scanf("%d", &n);
    for (int i = 0, x, y, z; i < n; i++) {
      scanf("%d%d%d", &x, &y, &z);
      p[z == -1].push_back({x, y});
    }
    bool ok = solve(n);
    if (ok)
      puts("Successful!");
    else
      puts("Infinite loop!");
  }
}
/*
5
2 4 1
5 4 1
2 1 1
5 1 1
3 1 -1
 */