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

struct Trie
{
    int next[500010][26], fail[500010], end[500010];
    int root, L;
    int newnode()
    {
        for (int i = 0; i < 26; i++)
            next[L][i] = -1;
        end[L++] = 0;
        return L - 1;
    }
    void init()
    {
        L = 0;
        root = newnode();
    }
    void insert(const string& buf)
    {
        int len = buf.length();
        int now = root;
        for (int i = 0; i < len; i++)
        {
            if (next[now][buf[i] - 'a'] == -1)
                next[now][buf[i] - 'a'] = newnode();
            now = next[now][buf[i] - 'a'];
        }
        end[now]++;
    }
    void build()
    {
        queue<int> Q;
        fail[root] = root;
        for (int i = 0; i < 26; i++)
            if (next[root][i] == -1)
                next[root][i] = root;
            else
            {
                fail[next[root][i]] = root;
                Q.push(next[root][i]);
            }
        while (!Q.empty())
        {
            int now = Q.front();
            Q.pop();
            for (int i = 0; i < 26; i++)
                if (next[now][i] == -1)
                    next[now][i] = next[fail[now]][i];
                else
                {
                    fail[next[now][i]] = next[fail[now]][i];
                    Q.push(next[now][i]);
                }
        }
    }
    int query(const string& buf)
    {
        int len = buf.length();
        int now = root;
        int res = 0;
        for (int i = 0; i < len; i++)
        {
            now = next[now][buf[i] - 'a'];
            int temp = now;
            while (temp != root)
            {
                res += end[temp];
                end[temp] = 0;
                temp = fail[temp];
            }
        }
        return res;
    }
    void debug()
    {
        for (int i = 0; i < L; i++)
        {
            printf("id = %3d,fail = %3d,end = %3d,chi = [", i, fail[i], end[i]);
            for (int j = 0; j < 26; j++)
                printf("%2d", next[i][j]);
            printf("]\n");
        }
    }
};

Trie ac;
const int maxn = 5e5 + 5;
string buf[maxn];
string tar;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        ac.init();
        int Max = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> buf[i];
            if (buf[i].length() > Max)
                Max = buf[i].length(), tar = buf[i];
        }
        bool flag = false;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (buf[i].length() == tar.length())
            {
                if (buf[i] != tar)
                {
                    flag = true;
                    cout << "No" << endl;
                    break;
                }
                else
                    cnt++;
            }
            else
                ac.insert(buf[i]);
        }
        if (flag) continue;

        ac.build();
        if (ac.query(tar) + cnt == n)
            cout << tar << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
