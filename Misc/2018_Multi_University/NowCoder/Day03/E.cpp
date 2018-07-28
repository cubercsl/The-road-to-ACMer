#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 21;
char s[N], t[N];
typedef long long ll;
unordered_map<ll, int> idx;
vector<vector<int> > ans;
int id[N];

int main()
{
    scanf("%s", s);
    int n = strlen(s);
    ll pw = 1;
    for (int i = 1; i < n; i++) pw *= 131;
    strcpy(t, s);
    strcat(s, t);
    ll val = 0;
    for (int i = 0, l = 0, r = 0; i < n; i++)
    {
        while (l < i) val -= pw * s[l++];
        while (r < i + n) val = val * 131 + s[r++];
        if (!idx.count(val))
        {
            idx[val] = ans.size();
            ans.push_back(vector<int>());
        }
        ans[idx[val]].push_back(i);
    }
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < ans.size(); i++)
    {
        for (auto& j : ans[i]) printf(" %d", j);
        puts("");
    }
    return 0;
}