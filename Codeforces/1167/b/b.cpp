#include <bits/stdc++.h>
using namespace std;

int ask(int x, int y)
{
    cout << "? " << x << " " << y << endl;
    int res;
    cin >> res;
    return res;
}

int main()
{
    vector<int> ans;
    set<int> s = {4, 8, 15, 16, 23, 42};
    int x = ask(1, 1);
    ans.push_back((int)sqrt(x));
    int y = ask(2, 2);
    ans.push_back((int)sqrt(y));
    for (auto& t : ans) s.erase(t);
    map<int, pair<int, int>> dic;
    for (auto& x : s)
        for (auto& y : s)
            dic[x * y] = make_pair(x, y);
    int u = ask(3, 4);
    int v = ask(3, 5);
    auto uu = dic[u], vv = dic[v];
    if (uu.first == vv.first)
    {
        ans.push_back(uu.first);
        ans.push_back(uu.second);
        ans.push_back(vv.second);
    }
    else if (uu.second == vv.first)
    {
        ans.push_back(uu.second);
        ans.push_back(uu.first);
        ans.push_back(vv.second);
    }
    else if (uu.first == vv.second)
    {
        ans.push_back(uu.first);
        ans.push_back(uu.second);
        ans.push_back(vv.first);
    }
    else
    {
        ans.push_back(uu.second);
        ans.push_back(uu.first);
        ans.push_back(vv.first);
    }
    for (int i = 2; i < ans.size(); i++) s.erase(ans[i]);
    ans.push_back(*s.begin());
    cout << "! ";
    for (auto& t : ans) cout << t << ' ';
    cout << endl;
}