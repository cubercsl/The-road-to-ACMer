#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    char c;
    cin >> n;
    set<char> s;
    while(n--)
    {
        cin >> c;
        s.insert(c);
    }
    if(s.size() == 3) cout << "Three" << endl;
    else cout << "Four" << endl;
    return 0;
}