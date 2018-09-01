#include <bits/stdc++.h>

int main()
{
    std::unordered_map<std::string, int> d;
    d["012345"] = 0;
    std::queue<std::string> q;
    q.push("012345");
    while (!q.empty())
    {
        std::string t = q.front();
        q.pop();
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                std::string s = t;
                if (i == j) continue;
                for (auto& ch : s)
                    if (ch - '0' == i) ch = '0' + j;
                if (d.count(s)) continue;
                d[s] = d[t] + 1;
                q.push(s);
            }
        }
    }
    std::string s, t;
    while (std::cin >> s >> t)
    {
        assert(s.length() == t.length());
        std::vector<int> cnt(6);
        std::vector<std::vector<int> > f(6, std::vector<int>(6));
        for (int i = 0; i < s.length(); i++)
        {
            ++cnt[t[i] - '1'];
            ++f[t[i] - '1'][s[i] - '1'];
        }
        int ans = s.length();
        for (auto& t : d)
        {
            int sum = t.second;
            for (int i = 0; i < 6; i++) sum += cnt[i] - f[i][t.first[i] - '0'];
            ans = std::min(ans, sum);
        }
        std::cout << ans << std::endl;
    }
}