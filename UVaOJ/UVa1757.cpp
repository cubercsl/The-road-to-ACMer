// Secret Chamber at Mount Rushmore, ACM/ICPC World Final 2017, UVa1757

/*Sample Input
9 5
c t
i r
k p
o c
r o
t e
t f
u h
w p
we we
can the
work people
it of
out the
3 3
a c
b a
a b
aaa abc
abc aaa
acm bcm
*/

#include <bits/stdc++.h>
using namespace std;

char s[60], t[60];
bool change[30][30];
bool vis[30];
bool ok;

void dfs(int ch, int id)
{
    if (ok)
        return;
    if (vis[ch])
        return;
    int tmp = t[id] - 'a';
    if (ch == tmp)
    {
        ok = 1;
        return;
    }
    vis[ch] = 1;
    for (int i = 0; i < 26; i++)
        if (change[ch][i])
            dfs(i, id);
}

int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        memset(change, 0, sizeof(change));
        while (n--)
        {
            char a, b;
            cin >> a >> b;
            change[a - 'a'][b - 'a'] = 1;
        }
        while (m--)
        {
            cin >> s >> t;
            ok = 0;
            if (strlen(s) == strlen(t))
                for (int i = 0; i < strlen(s); i++)
                {
                    ok = 0;
                    memset(vis, 0, sizeof(vis));
                    int ch = s[i] - 'a';
                    dfs(ch, i);
                    if (!ok)
                        break;
                }
            if (ok)
                cout << "yes" << endl;
            else
                cout << "no" << endl;
        }
    }
    return 0;
}
