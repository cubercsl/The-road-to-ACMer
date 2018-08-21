#include <bits/stdc++.h>
using namespace std;

vector<int> G[26];
const int N = 20;
char s[N], ans[N];
int m;
void gao(const char* s)
{
    bool flag = true;
    int cur = -1;
    for (int i = 0; s[i]; i++)
    {
        char t = s[i];
        int c = s[i] - 'a';
        if (flag)
        {
            auto it = upper_bound(G[c].begin(), G[c].end(), cur);
            if (it == G[c].end())
            {
                flag = false;
                ans[m] = t, G[c].push_back(m++);
            }
            else
                cur = *it;
        }
        else
            ans[m] = t, G[c].push_back(m++);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        m = 0;
        cin >> n;
        for (int i = 0; i < 26; i++) G[i].clear();
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            gao(s);
        }
        ans[m] = '\0';
        cout << ans << endl;
    }
}