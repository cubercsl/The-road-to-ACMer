#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 305;
ll a[N], b[N], c[N];

int main()
{
    int n, k;
    while (cin >> n >> k)
    {
        for (int i = 0; i <= n; i++) a[i] = 1;
        for (int kk = 1; kk < k; kk++)
        {
            memset(c, 0, sizeof(c));
            for (int i = 0; i <= n; i += (kk + 1)) b[i] = 1;
            for (int i = 0; i <= n; i++)
                for (int j = 0; j + i <= n; j++)
                    c[i + j] += a[i] * b[j];
            memcpy(a, c, sizeof(a));
            memset(b, 0, sizeof(b));
        }
        cout << a[n] << endl;
    }
}