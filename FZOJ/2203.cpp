// 单纵大法好, FZU2203

/*Sample Input
5 1 3
2
1 5
5 1 3
1
3
*/

#include <iostream>
using namespace std;

int x[200010], tmp[200010];
int n, k, a;
bool check(int num)
{
    for (int i = 1; i <= num; i++)
        tmp[i] = x[i];
    sort(tmp + 1, tmp + num + 1);
    tmp[0] = 0, tmp[num + 1] = n + 1;
    int cnt = 0;
    for (int i = 0; i <= num; i++)
        cnt += (tmp[i + 1] - tmp[i]) / (a + 1);
    if (cnt >= k)
        return true;
    return false;
}


int main()
{
    while (cin >> n >> k >> a)
    {
        int m;
        cin >> m;
        for (int i = 1; i <= m; i++)
            cin >> x[i];
        int l = 1, r = m, ans = 0;
        if (check(m))
            cout << -1 << endl;
        else
        {
            while (l <= r)
            {
                int mid = (l + r) / 2;
                if (check(mid))
                    ans = mid, l = mid + 1;
                else
                    r = mid - 1;
            }
            cout << ans + 1 << endl;
        }
    }
    return 0;
}
