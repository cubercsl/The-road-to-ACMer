#include <bits/stdc++.h>
using namespace std;

int tx[] = {0, 1, 0, -1};
int ty[] = {1, 0, -1, 0};

int main()
{
    int n, m;
    int a[10000];
    int maze[100][100];
    while (cin >> n >> m)
    {
        memset(maze, 0, sizeof(maze));
        for (int i = 0; i < m * n; i++)
            cin >> a[i];
        int dir = 0;
        int x = 0, y = 0;
        for (int i = 0; i < m * n; i++)
        {
            maze[x][y] = a[i];
            int nx = x + tx[dir];
            int ny = y + ty[dir];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || maze[nx][ny])
            {
                dir = (dir + 1) % 4;
                nx = x + tx[dir];
                ny = y + ty[dir];
            }
            x = nx, y = ny;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (j)
                    cout << " ";
                cout << maze[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}

// Verdict: Wrong Answer
