#include <bits/stdc++.h>
using namespace std;

bool check(const string& pat, const vector<string>& s)
{
    for (int i = 1; i < s.size(); i++)
    {
        const string& ss = s[i];
        int sz = ss.size() / 2;
        bool flag = false;
        for (int j = 0; j < sz && !flag; j++)
        {
            int k = j, kk = 0;
            for (; k < j + sz; k++)
                if (kk < pat.size() && ss[k] == pat[kk]) kk++;
            if (kk == pat.size()) flag = true;
        }
        if (!flag) return false;
    }
    return true;
}

int main()
{
    int n;
    while (cin >> n)
    {
        vector<string> s(n);
        for (auto& t : s) cin >> t;
        for (int i = 1; i < n; i++) s[i] = s[i] + s[i];
        int m = s[0].length();
        string ans = "{";
        for (int i = (1 << m) - 1; i; i--)
        {
            string t;
            int sz = 0;
            for (int j = 0; j < m; j++)
                if (i >> j & 1) t.push_back(s[0][j]), sz++;
            for (int j = 0; j < sz; j++)
            {   
                string pat = t.substr(j) + t.substr(0, j);
                if (pat.size() < ans.size()) continue;
                if (check(pat, s)) ans = min(ans, pat);
            }
            
        }
        if (ans == "{") ans = "0";
        cout << ans << endl;
    }
}