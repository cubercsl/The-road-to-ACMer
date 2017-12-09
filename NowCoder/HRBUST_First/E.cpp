#include <bits/stdc++.h>
using namespace std;

int main()
{
    string buf;
    int T;
    cin >> T;
    getline(cin, buf);
    while (T--)
    {
        getline(cin, buf);
        stringstream ss(buf);
        int num, sum = 0;
        while (ss >> num) sum += num;
        cout << sum << endl;
    }
    return 0;
}
