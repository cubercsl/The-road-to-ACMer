#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;;
    cin >> n >> m;
    vector<vector<int>> p(n + 1);
    for (int i = 1; i <= n; i++) p[i].push_back(i);
    for (int i = 0, a, b; i < m; i++)
    {
        cin >> a >> b;
        p[a].push_back(a * 1000 + b);
        p[b].push_back(a * 1000 + b);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << p[i].size() << endl;
        for (auto& t : p[i]) cout << i << " " << t << endl;
    }
}