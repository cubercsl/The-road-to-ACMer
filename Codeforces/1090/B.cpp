#include <bits/stdc++.h>
using namespace std;

map<string, string> bib;

const string beginbib = "\\begin{thebibliography}{99}";
const string bibitem = "\\bibitem";
const string endbib = "\\end{thebibliography}";
const string cite = "\\cite";

vector<string> cites;

inline string resolve(const string& s, const string& type)
{
    auto r = s.find('}');
    return string(s.begin() + type.length() + 1, s.begin() + r);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    while (cin >> s && s != beginbib)
    {
        if (s.find(cite) == string::npos) continue;
        cites.push_back(resolve(s, cite));
    }
    bool flag = true;
    getline(cin, s);
    for (int i = 0;; i++)
    {
        getline(cin, s);
        if (s == endbib) break;
        string item = resolve(s, bibitem);
        if (item != cites[i]) flag = false;
        bib[item] = s.substr(10 + item.length());        
    }
    if (flag)
        cout << "Correct\n";
    else
    {
        cout << "Incorrect\n";
        cout << beginbib << '\n';
        for (auto& item : cites)
        {
            cout << bibitem << '{' << item << '}';
            cout << bib[item];
            cout << '\n';
        }
        cout << endbib << '\n';
    }
}