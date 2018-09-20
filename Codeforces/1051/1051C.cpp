#include <bits/stdc++.h>
using namespace std;

const int N = 105;
vector<int> id[N];

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& t : a) cin >> t;
    for (int i = 0; i < n; i++) id[a[i]].push_back(i);
    int p = 0;
    for (int i = 0; i < N; i++)
        if (id[i].size() == 1) p ^= 1;
    string ans;
    for (int i = 0; i < n; i++) ans.push_back('A');
    int x = 0;
    for (int i = 0; i < N; i++)
    {
        if (id[i].size() == 1)
            ans[id[i][0]] = 'A' + x, x ^= 1;
    }
    if (p == 0)
    {
        cout << "YES\n";
        cout << ans << endl;
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            if(id[i].size() > 2)
            {
                ans[id[i][0]] = 'A' + x;
                cout << "YES\n";
                cout << ans << endl;
                return 0;
            }
        }
        cout << "NO\n";
    }
}