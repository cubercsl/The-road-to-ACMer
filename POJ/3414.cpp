// Pots, POJ3414

/*Sample Input
3 5 4
*/

#include <iostream>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;

const int maxn = 102;
int A, B, C;
pair<int, int> pre[maxn][maxn];
int vis[maxn][maxn];

void print(int a, int b)
{
    if (a == 0 && b == 0)
        return;
    int pa = pre[a][b].first, pb = pre[a][b].second;
    print(pa, pb);
    // 通过两种状态间的区别确定期间进行的操作
    if (pb == b && a == A)
        cout << "FILL(1)" << endl;
    else if (pa == a && b == B)
        cout << "FILL(2)" << endl;
    else if (pb == b && a == 0)
        cout << "DROP(1)" << endl;
    else if (pa == a && b == 0)
        cout << "DROP(2)" << endl;
    else if (pa > a)
        cout << "POUR(1,2)" << endl;
    else
        cout << "POUR(2,1)" << endl;
}

void bfs()
{
    memset(vis, -1, sizeof(vis));
    queue<pair<int, int> > q;
    while (!q.empty())
        q.pop();
    q.push(make_pair(0, 0));
    vis[0][0] = 0;
    while (!q.empty())
    {
        pair<int, int> temp = q.front();
        q.pop();
        int a = temp.first;
        int b = temp.second;
        if (a == C || b == C)
        {
            // 任务完成
            cout << vis[a][b] << endl;
            print(a, b);
            return;
        }
        int t1[] = {0, a, A, a, max(a + b - B, 0), min(a + b, A)};
        int t2[] = {b, 0, b, B, min(a + b, B), max(a + b - A, 0)};
        // 分别对应六种操作
        for (int i = 0; i < 6; i++)
            if (vis[t1[i]][t2[i]] == -1)
            {
                vis[t1[i]][t2[i]] = vis[a][b] + 1;
                pre[t1[i]][t2[i]] = make_pair(a, b);
                q.push(make_pair(t1[i], t2[i]));
            }
    }
    cout << "impossible" << endl;
}

int main()
{
    cin >> A >> B >> C;
    bfs();
    return 0;
}