#include <bits/stdc++.h>
using namespace std;

struct Pos {

    double x, y;

};
struct Edge {
    
    Pos p1, p2;
    friend bool operator <(const Edge& a, const Edge& b) {

        return a.p1.y < b.p1.y;

    }
    void sort() { if(p1.y > p2.y) std::swap(p1, p2); }
    double lerp(double y) {

        double a = (y - p1.y) / (p2.y - p1.y);
        return p1.x + a * (p2.x - p1.x);

    }

};

const int MAXN = 501000;
int n, m;
Edge e1[MAXN], e2[MAXN];

std::vector<int> le1, le2;
void calc(std::vector<std::tuple<double, double, double>>& slice, double y) {

    double minX1 = 1e5, maxX1 = -1e5, minX2 = 1e5, maxX2 = -1e5;
    for(int i : le1) {
        
        double x = e1[i].lerp(y);
        minX1 = std::min(minX1, x);
        maxX1 = std::max(maxX1, x);

    }
    for(int i : le2) {
        
        double x = e2[i].lerp(y);
        minX2 = std::min(minX2, x);
        maxX2 = std::max(maxX2, x);

    }
    double s = 0;
    double x = 0, z = 0;
    if(minX1 < maxX1) x = maxX1 - minX1;
    if(minX2 < maxX2) z = maxX2 - minX2;
    slice.emplace_back(x, z, y);

}

int main() {

    while(~std::scanf("%d%d", &n, &m)) {
        
        for(int i = 0; i < n; i++)
            std::scanf("%lf%lf", &e1[i].p1.x, &e1[i].p1.y);
        for(int i = 0; i < m; i++)
            std::scanf("%lf%lf", &e2[i].p1.y, &e2[i].p1.x);
        
        double minY1 = 1e5, maxY1 = -1e5;
        double minY2 = 1e5, maxY2 = -1e5;
        for(int i = 0; i < n; i++)
            minY1 = std::min(minY1, e1[i].p1.y), maxY1 = std::max(maxY1, e1[i].p1.y);
        for(int i = 0; i < m; i++)
            minY2 = std::min(minY2, e2[i].p1.y), maxY2 = std::max(maxY2, e2[i].p1.y);
        
        double minY = std::max(minY1, minY2), maxY = std::min(maxY1, maxY2);

        std::set<double> ys;
        for(int i = 0; i < n; i++)
            if(e1[i].p1.y >= minY && e1[i].p1.y <= maxY) ys.insert(e1[i].p1.y);
        for(int i = 0; i < m; i++)
            if(e2[i].p1.y >= minY && e2[i].p1.y <= maxY) ys.insert(e2[i].p1.y);

        for(int i = 0; i < n; i++)
            e1[i].p2 = e1[(i + 1) % n].p1;
        for(int i = 0; i < m; i++)
            e2[i].p2 = e2[(i + 1) % m].p1;
        for(int i = 0; i < n; i++)
            e1[i].sort();
        for(int i = 0; i < m; i++)
            e2[i].sort();
        
        std::sort(e1, e1 + n);
        std::sort(e2, e2 + m);

        std::vector<std::tuple<double, double, double>> slice;
        int c1 = 0, c2 = 0;
        le1.clear(), le2.clear();

        for(double y : ys) {

            while(c1 < n && e1[c1].p1.y <= y)
                le1.push_back(c1++);
            while(c2 < m && e2[c2].p1.y <= y)
                le2.push_back(c2++);

            std::vector<int> ne1, ne2;
            for(int i : le1)
                if(e1[i].p2.y >= y)
                    ne1.push_back(i);
            for(int i : le2)
                if(e2[i].p2.y >= y)
                    ne2.push_back(i);
            le1 = ne1, le2 = ne2;

            calc(slice, y);

        }

        double result = 0;
        for(int i = 0; i < int(slice.size()) - 1; ++i) {
            
            double x1 = std::get<0>(slice[i]), x2 = std::get<0>(slice[i + 1]), x0 = x2 - x1;
            double z1 = std::get<1>(slice[i]), z2 = std::get<1>(slice[i + 1]), z0 = z2 - z1;
            double y1 = std::get<2>(slice[i]), y2 = std::get<2>(slice[i + 1]), h = y2 - y1;
            result += (x0 * z0 / 3 + (x0 * z1 + x1 * z0) / 2 + x1 * z1) * h;

        }
        std::printf("%.10f\n", result);

    }

}