// Floating-Point Numbers, UVa11809

/*Sample Input
5.699141892149156e76
9.205357638345294e18
0e0
*/

#include <bits/stdc++.h>
using namespace std;

double M[10][31];
long long E[10][31];
const double diff = 1e-5;

void init()
{
    for (int i = 0; i <= 9; i++)
        for (int j = 1; j <= 30; j++)
        {
            long long e = (1 << j) - 1;
            double m = 1 - 1.0 / (1 << (i + 1));
            double t = log10(m) + e * log10(2);
            E[i][j] = t / 1;
            M[i][j] = pow(10, t - E[i][j]);
        }
}

void solve(double m, long long e)
{
    for (int i = 0; i <= 9; i++)
        for (int j = 1; j <= 30; j++)
            if (e == E[i][j] && fabs(m - M[i][j]) < diff)
            {
                cout << i << " " << j << endl;
                return;
            }
}

int main()
{
    init(); // 打表预处理
    char str[22];
    double m;
    long long e;
    while (cin >> str, strcmp(str, "0e0"))
    {
        *(strchr(str, 'e')) = ' ';
        sscanf(str, "%lf %lld", &m, &e);
        solve(m, e);
    }
    return 0;
}
