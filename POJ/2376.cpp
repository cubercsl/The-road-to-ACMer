// Cleaning Shifts, POJ2376

/*Sample Input
3 10
1 7
3 6
6 10
*/

#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
struct node
{
    int L, R;
} cow[25010];

bool cmp(node a, node b)
{
    if (a.L == b.L)
        return a.R < b.R;
    return a.L < b.L;
}

int main()
{
    int n, t;
    cin >> n >> t;
    for (int i = 0; i < n; i++)
        cin >> cow[i].L >> cow[i].R;
    sort(cow, cow + n, cmp);
    int cnt = 0, tmp = 0, now = 0;
    while (now < t)
    {
        int min = now + 1;
        for (int i = tmp; i < n; i++)
            if (cow[i].L <= min && cow[i].R >= min)
                now = max(now, cow[i].R);
            else if (cow[i].L > min)
            {
                tmp = i;
                break;
            }
        if (min > now)
            break;
        else
            cnt++;
    }
    if (now >= t)
        cout << cnt << endl;
    else
        cout << -1 << endl;
    return 0;
}
