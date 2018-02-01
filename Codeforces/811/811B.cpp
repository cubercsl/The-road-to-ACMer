#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        int p[10000];
        for (int i = 0; i < n; i++)
            cin >> p[i];
        while (m--)
        {
            int l, r, x;
            cin >> l >> r >> x;
            int cnt = 0;
            for (int i = l - 1; i < r; i++)
                if (p[x - 1] > p[i])
                    cnt++;
            if (cnt == x - l)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
    return 0;
}
