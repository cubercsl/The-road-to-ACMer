// Prime Path, POJ 3126;

/*Sample Input
3
1033 8179
1373 8017
1033 1033
*/

#include <iostream>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;
const int maxn = 100010;

struct node
{
    int num, step;
};

queue<node> q;
int ST, END;
bool vis[maxn];

bool isprime(int n)
{
    if (n == 1)
        return false;
    for (int i = 2; i <= (int)sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}

int bfs()
{
    node temp, next;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        int NUM = temp.num, STEP = temp.step;
        if (NUM == END)
            return STEP;
        for (int i = 1; i <= 9; i += 2)
        {
            int S = NUM / 10 * 10 + i;
            if (S != NUM && !vis[S] && isprime(S))
            {
                vis[S] = 1;
                next.num = S;
                next.step = STEP + 1;
                q.push(next);
            }
        }
        for (int i = 0; i <= 9; i++)
        {
            int S = NUM / 100 * 100 + i * 10 + NUM % 10;
            if (S != NUM && !vis[S] && isprime(S))
            {
                vis[S] = 1;
                next.num = S;
                next.step = STEP + 1;
                q.push(next);
            }
        }
        for (int i = 0; i <= 9; i++)
        {
            int S = NUM / 1000 * 1000 + i * 100 + NUM % 100;
            if (S != NUM && !vis[S] && isprime(S))
            {
                vis[S] = 1;
                next.num = S;
                next.step = STEP + 1;
                q.push(next);
            }
        }
        for (int i = 1; i <= 9; i++)
        {
            int S = i * 1000 + NUM % 1000;
            if (S != NUM && !vis[S] && isprime(S))
            {
                vis[S] = 1;
                next.num = S;
                next.step = STEP + 1;
                q.push(next);
            }
        }
    }
    return -1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        while (!q.empty())
            q.pop();
        memset(vis, 0, sizeof(vis));
        cin >> ST >> END;
        node temp;
        temp.num = ST;
        temp.step = 0;
        q.push(temp);
        int ans = bfs();
        if (ans == -1)
            cout << "Impossible" << endl;
        else
            cout << ans << endl;
    }
}
