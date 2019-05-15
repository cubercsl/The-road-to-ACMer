#include<bits/stdc++.h>
using namespace std;
using ld = long double;
const int maxn = 3000;
const double eps = 1e-8;
#define zero(x) ((fabs(x) < eps ? 1 : 0))
#define sgn(x) (fabs(x) < eps ? 0 : ((x) < 0 ? -1 : 1))
struct point
{
    double x, y;
    point(double a = 0, double b = 0) { x = a, y = b; }
    point operator-(const point& b) const { return point(x - b.x, y - b.y); }
    point operator+(const point& b) const { return point(x + b.x, y + b.y); }
    // 两点是否重合
    bool operator==(point& b) { return zero(x - b.x) && zero(y - b.y); }
    // 点积(以原点为基准)
    double operator*(const point& b) const { return x * b.x + y * b.y; }
    // 叉积(以原点为基准)
    double operator^(const point& b) const { return x * b.y - y * b.x; }
};
double area(point p[], int n)
{
    double res = 0;
    for (int i = 0; i < n; i++) res += (p[i] ^ p[(i + 1) % n]) / 2;
    return fabs(res);
}

point p[maxn];

ld C[maxn][maxn];
void CalComb(){
    C[0][0] = 1;
    for (int i = 1; i < maxn; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]);
    }
}
ld x[maxn],y[maxn];
int main(){
    CalComb();
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%lf%lf",&p[i].x,&p[i].y);
    }
    ld ans = 0;
    for(int i=0;i<n;i++){
        /*
        for(int j=1;j<=n-k+1;j++){
            int q = (i + j) % n;
            ld tmp = -(p[i] ^ p[q]) / 2;
            ans += tmp * C[n-j-1][k-2];
        }
        */
        // /*
        for(int j=i+1;j<n;j++){
            int cnt = j - i + 1;
            ld tmp = (p[j] ^ p[i]) / 2;
            if(cnt >= 2)
                ans += tmp * C[cnt - 2][k - 2];
            cnt = n - cnt + 2;
            tmp = (p[i] ^ p[j]) / 2;
            if(cnt >= 2)
                ans += (tmp) * C[cnt - 2][k - 2];
        }
        // */
    }
    printf("%.10Lf\n", -ans / C[n][k]);
}