// Stall Reservations, POJ3190

/*Sample Input
5
1 10
2 4
3 6
5 8
4 7
*/

#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn = 5e4 + 5;
int n, ans[maxn];
struct Cow
{
    int L, R, id;
    bool operator < (const Cow &b) const
    {
        return L < b.L;
    }
} cow[maxn];

struct Stall
{
    int end, id;
    bool operator <(const Stall &b) const
    {
        return end > b.end;

    }
};

priority_queue<Stall> q;

void put_cow(int i, int new_stall)
{
    Stall s;
    if (new_stall)
        s.id = q.size() + 1;
    else
    {
        s.id = q.top().id;
        q.pop();
    }
    s.end = cow[i].R;
    ans[cow[i].id] = s.id;
    q.push(s);
}

void solve()
{
    put_cow(0, 1);
    for (int i = 1; i < n; i++)
        put_cow(i, cow[i].L <= q.top().end);
    int cnt = q.size();
    printf("%d\n", cnt);
    for (int i = 0; i < n; i++)
        printf("%d\n", ans[i]);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        cow[i].id = i;
        scanf("%d%d", &cow[i].L, &cow[i].R);
    }
    sort(cow, cow + n);
    solve();
    return 0;
}
