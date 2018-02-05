#include <bits/stdc++.h>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;

struct card
{
    int id;
    char type;
    card() {}
    card(int id, char type) : id(id), type(type) {}
    void read() { scanf("%d%c", &id, &type); }
    void print() { printf("%d%c", id, type); }
} hand[14];

char T[] = "mspc";
inline int id(char c)
{
    switch (c)
    {
    case 'm': return 1;
    case 's': return 2;
    case 'p': return 3;
    case 'c': return 4;
    }
}

int cnt[5][10];

bool dfs(int t1, int t2, int eye, int r, int c)
{
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j < (i == r ? c : 9); j++)
            if (cnt[i][j]) return false;
    }
    if (eye == 1 && cnt[r][c] != 3 && cnt[r][c] != 0 && ((c == 9 && cnt[r][c - 1] == 0) || (c == 1 && cnt[r][c + 1] == 0) || (1 < c && c < 9 && cnt[r][c + 1] == 0 && cnt[r][c - 1] == 0)))
        return false;
    if (eye == 0 && cnt[r][c] == 4 && cnt[r][c] == 1 && ((c == 9 && cnt[r][c - 1] == 0) || (c == 1 && cnt[r][c + 1] == 0) || (1 < c && c < 9 && cnt[r][c + 1] == 0 && cnt[r][c - 1] == 0)))
        return false;
    if (t1 + t2 == 4 && eye)
        return true;
    for (int i = r; i <= 4; ++i)
    {
        for (int j = (i == r ? c : 1); j <= 9; ++j)
        {
            if (eye == 0)
            {
                if (cnt[i][j] >= 2)
                {
                    cnt[i][j] -= 2;
                    if (dfs(t1, t2, 1, i, j) == true)
                        return true;
                    cnt[i][j] += 2;
                }
            }
            if (cnt[i][j] >= 3)
            {
                cnt[i][j] -= 3;
                if (dfs(t1 + 1, t2, eye, i, j) == true)
                    return true;
                cnt[i][j] += 3;
            }
            if (i != 4 && j <= 7 && cnt[i][j] >= 1 && cnt[i][j + 1] >= 1 && cnt[i][j + 2] >= 1)
            {
                cnt[i][j]--;
                cnt[i][j + 1]--;
                cnt[i][j + 2]--;
                if (dfs(t1, t2 + 1, eye, i, j) == true)
                    return true;
                cnt[i][j]++;
                cnt[i][j + 1]++;
                cnt[i][j + 2]++;
            }
        }
    }
    return false;
}

bool judge(card* hand)
{
    clr(cnt, 0);
    for (int i = 0; i < 14; i++) cnt[id(hand[i].type)][hand[i].id]++;

    // 七对子
    int eye = 0;
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 9; j++)
        {
            if (cnt[i][j] > 4) return false;
            eye += cnt[i][j] == 2;
        }

    if (eye == 7) return true;

    // 十三幺
    int p;
    for (p = 1; p < 4 && cnt[p][1] && cnt[p][9]; p++)
        ;
    if (p == 4)
    {
        for (p = 1; p <= 7 && cnt[4][p]; p++)
            ;
        if (p == 8)
        {
            for (int i = 1; i < 4; i++)
                if (cnt[i][1] == 2 || cnt[i][9] == 2) return true;
            for (int i = 1; i <= 7; i++)
                if (cnt[4][i] == 2) return true;
        }
    }

    return dfs(0, 0, 0, 1, 1);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int t;
    scanf("%d", &t);
    while (t--)
    {
        vector<card> ans;
        for (int i = 0; i < 13; i++) hand[i].read();
        for (int i = 1; i <= 4; i++)
        {
            int up = i != 4 ? 9 : 7;
            for (int j = 1; j <= up; j++)
            {
                hand[13] = card(j, T[i - 1]);
                if (judge(hand)) ans.pb(hand[13]);
            }
        }
        int n = ans.size();
        if (n)
        {
            printf("%d ", n);
            for (int i = 0; i < n; i++)
            {
                ans[i].print();
                printf("%c", i == n - 1 ? '\n' : ' ');
            }
        }
        else
            puts("Nooten");
    }
    return 0;
}
