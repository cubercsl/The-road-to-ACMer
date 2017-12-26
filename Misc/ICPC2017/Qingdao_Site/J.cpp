#include <bits/stdc++.h>
using namespace std;

const int N = 500000;
string s[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }
        string mm;
        for (int i = n - 1; ~i; i--) {
            int len = s[i].length();
            s[i] += mm;
            mm = s[i];
            for (int j = 0; j < len; j++) {
                mm = min(mm, s[i].substr(j));
            }
        }
        cout << mm << endl;
    }
    return 0;
}
