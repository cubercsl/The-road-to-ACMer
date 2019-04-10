#include <bits/stdc++.h>
using namespace std;

bool solve(int x, const vector<int>& a, int n)
{
    vector<int> ans(n);
    multiset<int> dic;
    for (int i = 2; i < a.size(); i++) dic.insert(a[i]);
    ans[0] = (a[0] + a[1] - x) / 2;
    ans[1] = a[0] - ans[0];
    ans[2] = a[1] - ans[0];
    if (ans[0] < 0 || ans[1] < 0 || ans[2] < 0) return false;
    dic.erase(dic.find(x));
    for (int i = 3; i < n; i++)
    {
        ans[i] = *dic.begin() - ans[0];
        if (ans[i] < 0) return false;
        for (int j = 0; j < i; j++)
        {
            auto it = dic.find(ans[i] + ans[j]);
            if (it == dic.end()) return false;
            dic.erase(it);
        }
    }
    for (auto& t : ans) printf("%d ", t);
    puts("");
    return true;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        int m = n * (n - 1) / 2;
        vector<int> a(m);
        for (int i = 0; i < m; i++) scanf("%d", &a[i]);
        for (int i = 2; i < n; i++)
            if (solve(a[i], a, n)) break;
    }
}