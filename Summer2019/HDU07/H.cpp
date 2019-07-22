#include <bits/stdc++.h>

using i64 = long long;

const int MAXN = 60000;
const double PI = std::atan(1) * 4;

int t;
int n;
struct Point {
    double at;
    int value;
    friend bool operator <(const Point& a, const Point& b) { return a.at < b.at; }
    friend bool operator <(const Point& a, double b) { return a.at < b; }
};
Point points[MAXN];
i64 sum[MAXN];

int main() {
    
    std::scanf("%d", &t);
    for(int test = 0; test < t; ++test) {
        
        std::scanf("%d", &n);
        for(int i = 0; i < n; ++i) {
            
            int x, y;
            std::scanf("%d%d%d", &x, &y, &points[i].value);
            points[i].at = std::atan2(y, x);

        }
        std::sort(points, points + n);
        int index0 = 0, index1 = std::lower_bound(points, points + n, points[0].at + PI) - points;
        if(index1 == n) index1 = 0;

        sum[0] = 0;
        for(int i = 0; i < n; ++i)
            sum[i + 1] = sum[i] + points[i].value;

        i64 current = sum[index1] * (sum[n] - sum[index1]), result = current;
        double angle = points[0].at;
        do {

            double angle0 = points[index0].at - angle, angle1 = points[index1].at - angle - PI;
            if(angle0 <= angle1) {
                
                angle = points[index0].at;
                ++index0;

            } else {
                
                angle = points[index1].at;
                ++index1;

            }
            i64 x = sum[index1] - sum[index0];
            current = x * (sum[n] - x);
            result = std::max(result, current);

        } while(index1 < n);
        std::printf("%lld\n", result);

    }

    return 0;
}