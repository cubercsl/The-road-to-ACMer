#include <bits/stdc++.h>
#define Tcase int T; cin >> T; while(T--)
using namespace std;
const int maxn = 5005;

struct node
{
    int l, w;
    bool flag;
    bool operator < (const node &a) const
    {
        return l < a.l;
    }
} st[maxn];

int main()
{
    Tcase
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> st[i].l >> st[i].w;
            st[i].flag = 0;
        }
        sort(st, st + n);
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            int l_now = 0, w_now = 0, j;
            for (j = i; j < n; j++)
                if (!st[j].flag)
                {

                    l_now = st[j].l, w_now = st[j].w, st[j].flag = 1;
                    cnt++;
                    break;
                }
            for (; j < n; j++)
                if (!st[j].flag && st[j].l >= l_now && st[j].w >= w_now)
                    l_now = st[j].l, w_now = st[j].w, st[j].flag = 1;
        }
        cout << cnt << endl;
    }
}
