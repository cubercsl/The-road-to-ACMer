#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 5;
int C[maxn];
int n;
int lowbit(int x)
{
    return (-x) & x;
}
void update(int x, int y)
{
    for (int i = x; i > 0; i -= lowbit(i))
        C[i] += y;
}
int query(int x)
{
    int s = 0;
    for (int i = x; i <= n; i += lowbit(i))
        s += C[i];
    return s;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(C, 0, sizeof(C));
        int m;
        cin >> n >> m;
        while (m--)
        {
            char cmd;
            cin >> cmd;
            if (cmd == 'P')
            {
                int a, b;
                cin >> a >> b;
                update(b, 1);
                update(a - 1, -1);
            }
            else
            {
                int a;
                cin >> a;
                cout << query(a) << endl;
            }
        }
    }
    return 0;
}
