#include <bits/stdc++.h>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<VI> G(50, VI(50));
    --a, --d;
    if (d <= 25)
        for (int i = 0; i < d * 2; i += 2) G[0][i] = 4;
    else if (d <= 50)
    {
        for (int i = 0; i < 50; i += 2) G[0][i] = 4;
        for (int i = 0; i < (d - 25) * 2; i += 2) G[2][i] = 4;
    }
    else if (d <= 75)
    {
        for (int i = 0; i < 50; i += 2) G[0][i] = G[2][i] = 4;
        for (int i = 0; i < (d - 50) * 2; i += 2) G[4][i] = 4;
    }
    else
    {
        for (int i = 0; i < 50; i += 2) G[0][i] = G[2][i] = G[4][i] = 4;
        for (int i = 0; i < (d - 75) * 2; i += 2) G[6][i] = 4;
    }
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 50; j++)
            if (!G[i][j]) G[i][j] = 1;
    if (a <= 25)
        for (int i = 0; i < a * 2; i += 2) G[10][i] = 1;
    else if (a <= 50)
    {
        for (int i = 0; i < 50; i += 2) G[10][i] = 1;
        for (int i = 0; i < (a - 25) * 2; i += 2) G[12][i] = 1;
    }
    else if (a <= 75)
    {
        for (int i = 0; i < 50; i += 2) G[10][i] = G[12][i] = 1;
        for (int i = 0; i < (a - 50) * 2; i += 2) G[14][i] = 1;
    }
    else
    {
        for (int i = 0; i < 50; i += 2) G[10][i] = G[12][i] = G[14][i] = 1;
        for (int i = 0; i < (a - 75) * 2; i += 2) G[16][i] = 1;
    }
    if (b <= 25)
        for (int i = 0; i < b * 2; i += 2) G[20][i] = 2;
    else if (b <= 50)
    {
        for (int i = 0; i < 50; i += 2) G[20][i] = 2;
        for (int i = 0; i < (b - 25) * 2; i += 2) G[22][i] = 2;
    }
    else if (b <= 75)
    {
        for (int i = 0; i < 50; i += 2) G[20][i] = G[22][i] = 2;
        for (int i = 0; i < (b - 50) * 2; i += 2) G[24][i] = 2;
    }
    else
    {
        for (int i = 0; i < 50; i += 2) G[20][i] = G[22][i] = G[24][i] = 2;
        for (int i = 0; i < (b - 75) * 2; i += 2) G[26][i] = 2;
    }
    if (c <= 25)
        for (int i = 0; i < c * 2; i += 2) G[30][i] = 3;
    else if (c <= 50)
    {
        for (int i = 0; i < 50; i += 2) G[30][i] = 3;
        for (int i = 0; i < (c - 25) * 2; i += 2) G[32][i] = 3;
    }
    else if (c <= 75)
    {
        for (int i = 0; i < 50; i += 2) G[30][i] = G[32][i] = 3;
        for (int i = 0; i < (c - 50) * 2; i += 2) G[34][i] = 3;
    }
    else
    {
        for (int i = 0; i < 50; i += 2) G[30][i] = G[32][i] = G[34][i] = 3;
        for (int i = 0; i < (c - 75) * 2; i += 2) G[36][i] = 3;
    }
    cout << 50 << " " << 50 << endl;
    for (int i = 0; i < 50; i++)
    {
        for (int j = 0; j < 50; j++)
            if (G[i][j] == 1)
                cout << "A";
            else if (G[i][j] == 2)
                cout << "B";
            else if (G[i][j] == 3)
                cout << "C";
            else
                cout << "D";
        cout << endl;
    }
    return 0;
}
