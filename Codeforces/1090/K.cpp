#include <bits/stdc++.h>
using namespace std;

map<pair<string, int>, vector<int>> G;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string s, t;
    for (int i = 0; i < n; i++)
    {
        cin >> s >> t;
        int mask = 0;
        for (auto& ch : t) mask |= 1 << (ch - 'a');
        while (!s.empty() && mask >> (s.back() - 'a') & 1) s.pop_back();
        G[{s, mask}].push_back(i + 1);
    }
    cout << G.size() << '\n';
    for (const auto& t : G)
    {
        cout << t.second.size();
        for (const auto& it : t.second) cout << ' ' << it;
        cout << '\n';
    }
}