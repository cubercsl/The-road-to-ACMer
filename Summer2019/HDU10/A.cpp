#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
class Node
{
private:
    int a[6][6];
    ull hash = 0;
    void update()
    {
        hash = 0;
        for (int i = 0; i < 6; i++)
            for (int j = 0; j < i + 1; j++)
                hash = hash * 6 + a[i][j];
    }

public:
    Node()
    {
        for (int i = 0; i < 6; i++)
            for (int j = 0; j < i + 1; j++)
                a[i][j] = i;
        update();
    }

    Node(int a[6][6])
    {
        for (int i = 0; i < 6; i++)
            for (int j = 0; j < i + 1; j++)
                this->a[i][j] = a[i][j];
        update();
    }

    Node(const Node& x)
    {
        *this = x;
    }

    ull operator()() const
    {
        return hash;
    }
    Node operator+(int op)
    {
        Node ret(*this);
        int x = -1, y = -1;
        for (int i = 0; i < 6; i++)
            for (int j = 0; j < i + 1; j++)
                if (!a[i][j]) x = i, y = j;
        assert(~x && ~y);
        int xx = -1, yy = -1;
        switch (op)
        {
        case 0:
            xx = x - 1, yy = y - 1;
            break;
        case 1:
            xx = x - 1, yy = y;
            break;
        case 2:
            xx = x + 1, yy = y;
            break;
        case 3:
            xx = x + 1, yy = y + 1;
            break;
        }
        if (xx < 0 || yy < 0 || yy > xx || xx > 5) throw std::exception();
        swap(ret.a[x][y], ret.a[xx][yy]);
        ret.update();
        return ret;
    }
    void debug()
    {
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < i + 1; j++)
                printf("%d ", a[i][j]);
            puts("");
        }
    }
};

int a[6][6];
unordered_map<ull, int> vis[2];
int bfs(const Node& s, const Node& t)
{
    vis[0].clear(), vis[1].clear();
    queue<Node> q[2];
    q[0].push(s);
    q[1].push(t);
    vis[0][s()] = 0;
    vis[1][t()] = 0;
    while (!q[0].empty() || !q[1].empty())
    {
        for (int d = 0; d < 2; d++)
        {
            int n = q[d].size();
            while (n--)
            {
                auto u = q[d].front();
                q[d].pop();
                if (vis[d ^ 1].count(u())) return vis[d][u()] + vis[d ^ 1][u()];
                for (int i = 0; i < 4; i++)
                {
                    try
                    {
                        auto v = u + i;
                        if (vis[d].count(v())) continue;
                        vis[d][v()] = vis[d][u()] + 1;
                        if (vis[d][v()] > 10)
                        {
                            puts("too difficult");
                            return -1;
                        }
                        q[d].push(v);
                    }
                    catch (const std::exception& e)
                    {
                        continue;
                    }
                }
            }
        }
    }
    assert(false);
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        for (int i = 0; i < 6; i++)
            for (int j = 0; j < i + 1; j++)
                scanf("%d", &a[i][j]);
        Node s(a), t;
        int ans = bfs(s, t);
        if (~ans) printf("%d\n", ans);
    }
}