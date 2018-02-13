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

const char type[] = "mspc";
int convert(char* s)
{
    for (int i = 0; i < 4; i++)
        if (type[i] == s[1])
            return s[0] - '1' + i * 9;
    assert(false);
}

int c[34];

bool seven_pair()
{
    int cnt = 0;
    for (int i = 0; i < 34; i++)
        if (c[i] == 2) cnt++;
    return cnt == 7;
}

bool thirteen_orphans()
{
    int sum = 0, cnt = 0;
    for (int i = 0; i < 34; i++)
        if (i >= 27 || i % 9 == 0 || i % 9 == 8)
            cnt += c[i] == 2, sum += c[i] == 1;
    return cnt == 1 && sum == 12;
}

// bool dfs(int dep)
// {
//     if (dep == 4) return true;
//     // 刻
//     for (int i = 0; i < 34; i++)
//         if (c[i] >= 3)
//         {
//             c[i] -= 3;
//             if (dfs(dep + 1)) return true;
//             c[i] += 3;
//         }
//     // 顺
//     for (int i = 0; i < 27; i++)
//         if (i % 9 < 7 && c[i] && c[i + 1] && c[i + 2])
//         {
//             c[i]--, c[i + 1]--, c[i + 2]--;
//             if (dfs(dep + 1)) return true;
//             c[i]++, c[i + 1]++, c[i + 2]++;
//         }
//     return false;
// }

vector<int> p;
bool f[35];
bool dfs(int dep)
{
    if (dep == 4) return true;
    int i, j, k;
    for (i = 0; f[i]; ++i)
        ;
    for (j = i + 1; j < 12; ++j)
        if (!f[j] && p[j] == p[i]) break;
    for (k = j + 1; k < 12; ++k)
        if (!f[k] && p[k] == p[i]) break;
    if (j < 12 && k < 12)
    {
        f[i] = f[j] = f[k] = 1;
        if (dfs(dep + 1)) return true;
        f[i] = f[j] = f[k] = 0;
    }
    if (p[i] < 27 && p[i] % 9 < 7)
    {
        for (j = i + 1; j < 12; ++j)
            if (!f[j] && p[j] == p[i] + 1) break;
        for (k = j + 1; k < 12; ++k)
            if (!f[k] && p[k] == p[i] + 2) break;
        if (j < 12 && k < 12)
        {
            f[i] = f[j] = f[k] = 1;
            if (dfs(dep + 1)) return true;
            f[i] = f[j] = f[k] = 0;
        }
    }
    return false;
}

bool check()
{
    if (seven_pair() || thirteen_orphans()) return true;
    for (int i = 0; i < 34; i++)
        if (c[i] > 1)
        {
            c[i] -= 2;
            p.clear(), clr(f, 0);
            // if (dfs(0)) return true;
            for (int j = 0; j < 34; j++)
                for (int k = 0; k < c[j]; k++)
                    p.pb(j);
            if (dfs(0)) return true;
            c[i] += 2;
        }
    return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    int mj[15];
    char s[5];
    while (T--)
    {
        for (int i = 0; i < 13; i++)
        {
            scanf("%s", s);
            mj[i] = convert(s);
        }
        vector<int> ans;
        for (int i = 0; i < 34; i++)
        {
            clr(c, 0);
            for (int j = 0; j < 13; j++) c[mj[j]]++;
            if (c[i] >= 4) continue;
            c[i]++;
            if (check()) ans.pb(i);
            c[i]--;
        }
        int n = ans.size();
        if (n == 0)
            puts("Nooten");
        else
        {
            printf("%d", n);
            for (auto t : ans)
                printf(" %d%c", t % 9 + 1, type[t / 9]);
            puts("");
        }
    }
    return 0;
}