// Catch That Cow, POJ3278

/*Sample Input
5 17
*/
#include <iostream>
#include <queue>
using namespace std;

const int maxn = 100005;

struct Node
{
    int num;
    int dis;
} s;

bool vis[maxn];

int bfs(int k)
{
    queue<Node> q;
    q.push(s);
    while (!q.empty())
    {
        Node temp = q.front();
        q.pop();
        if (temp.num == k)
            return temp.dis;
        if (temp.num < 0 || temp.num > maxn || vis[temp.num])
            continue;
        s.dis = temp.dis + 1;
        s.num = temp.num * 2;
        q.push(s);
        s.num = temp.num + 1;
        q.push(s);
        s.num = temp.num - 1;
        q.push(s);
        vis[temp.num] = 1;
    }
    return -1;
}

int main()
{
    int n, k;
    cin >> n >> k;
    s.num = n;
    s.dis = 0;
    cout << bfs(k) << endl;
    return 0;
}