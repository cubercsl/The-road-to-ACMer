#include <bits/stdc++.h>
using namespace std;
#define clr(a,x) memset(a, x, sizeof(a))
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3fdd3f;
const double eps = 1e-6;

const int maxn = 370000;
int f[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320};
bool vis[maxn];
int pre[maxn];
int path[maxn];

int cantor(int s[])
{
    int ans = 0;
    for (int i = 0; i < 9; i++)
    {
        int num = 0;
        for (int j = i + 1; j < 9; j++)
            if (s[j] < s[i]) num++;
        ans += (num * f[9 - i - 1]);
    }
    return ans;
}

struct node
{
    int s[9];
    int blank;
    int hash;
};

int tx[] = { -1, 0, 1, 0};
int ty[] = {0, -1, 0, 1};
const char dir[] = "drul";

const int tar = 46233;

void bfs()
{
    clr(vis, 0);
    node tmp, nxt;
    for (int i = 0; i < 8; i++) tmp.s[i] = i + 1;
    tmp.s[8] = 0;
    tmp.blank = 8;
    tmp.hash = tar;
    queue<node> q;
    q.push(tmp);
    while (!q.empty())
    {
        tmp = q.front();
        q.pop();
        int x = tmp.blank / 3;
        int y = tmp.blank % 3;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + tx[i];
            int ny = y + ty[i];
            if (nx < 0 || ny < 0 || nx >= 3 || ny >= 3) continue;
            nxt = tmp;
            nxt.blank = nx * 3 + ny;
            nxt.s[tmp.blank] = nxt.s[nxt.blank];
            nxt.s[nxt.blank] = 0;
            nxt.hash = cantor(nxt.s);
            if (!vis[nxt.hash])
            {
                vis[nxt.hash] = true;
                pre[nxt.hash] = tmp.hash;
                path[nxt.hash] = i;
                q.push(nxt);
            }
        }
    }
}

void print(int cur)
{
    while (cur != tar)
    {
        cout << dir[path[cur]];
        cur = pre[cur];
    }
    cout << endl;
}


int main()
{
#ifndef ONLINE_JUDGE
//    freopen("1.in", "r", stdin);
//    freopen("1.out", "w", stdout);
#endif
    //int s[] = {1, 2, 3, 4, 5, 6, 7, 8, 0};
    //cout << cantor(s) << endl;
    bfs();
    char ch;
    node cur;
    while (cin >> ch)
    {
        if (ch == 'x')
            cur.s[0] = 0, cur.blank = 0;
        else cur.s[0] = ch - '0';
        for (int i = 1; i < 9; i++)
        {
            cin >> ch;
            if (ch == 'x')
                cur.s[i] = 0, cur.blank = i;
            else cur.s[i] = ch - '0';
        }
        cur.hash = cantor(cur.s);
        if (vis[cur.hash])
            print(cur.hash);
        else
            cout << "unsolvable" << endl;
    }
    return 0;
}
