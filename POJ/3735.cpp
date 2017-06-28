// Training little cats, POJ3735

/*Sample Input
3 1 6
g 1
g 2
g 2
s 1 2
g 3
e 2
0 0 0
*/

#include <cstdio>
#include <vector>
#include <cstring>
#define input(n) while(cin >> n)
#define input_2(a, b) while(cin >> a >> b)
#define Tcase int T; cin >> T; while(T--)
#define clr(x, y) memset(x, y, sizeof(x))
#define pb push_back
#define mp make_pair
#define lowbit(x) (x & -x)
#define Lson L, mid, node << 1
#define Rson mid + 1, R, node << 1 | 1
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;

typedef vector <ll> vec;
typedef vector <vec> mat;

mat mul(mat &A, mat &B)
{
    mat C(A.size(), vec(B[0].size()));
    for (int i = 0; i < A.size(); i++)
        for (int k = 0; k < B.size(); k++)
            if (A[i][k])
                for (int j = 0; j < B[0].size(); j++)
                    C[i][j] += A[i][k] * B[k][j];
    return C;
}

mat fast_pow (mat A, ll n)
{
    mat B(A.size(), vec(A.size()));
    for (int i = 0; i < A.size(); i++)
        B[i][i] = 1;
    while (n)
    {
        if (n & 1)
            B = mul(B, A);
        A = mul(A, A);
        n >>= 1;
    }
    return B;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m, k;
    while (scanf("%d%d%d", &n, &m, &k), n || m || k)
    {
        mat A(n + 1, vec(n + 1));
        for (int i = 0; i < A.size(); i++)
            A[i][i]  = 1;
        while (k--)
        {
            char cmd[2];
            scanf("%s", cmd);
            if (cmd[0] == 'g')
            {
                int id;
                scanf("%d", &id);
                A[id - 1][n]++;
            }
            else if (cmd[0] == 'e')
            {
                int id;
                scanf("%d", &id);
                for (int i = 0; i <= n; i++)
                    A[id - 1][i] = 0;
            }
            else
            {
                int a, b;
                scanf("%d%d", &a, &b);
                for (int i = 0; i <= n; i++)
                    swap(A[a - 1][i], A[b - 1][i]);
            }
        }
        A = fast_pow(A, m);
        vec col(n + 1);
        vec ans(n + 1);
        col[n] = 1;
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= n; j++)
                ans[i] += A[i][j] * col[j];
            if (i)
                putchar(' ');
            if (i != n)
                printf("%lld", ans[i]);
        }
        putchar('\n');
    }
    return 0;
}
