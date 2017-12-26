#include <bits/stdc++.h>
using namespace std;

char m[5][5];
void solve()
{
    for (int i = 0; i < 3; i++) {
        if (m[i][0] != '.' && m[i][0] == m[i][1] && m[i][1] == m[i][2]) {
            cout << m[i][0] << endl;
            return;
        }
    }
    for (int i = 0; i < 3; i++) {
        if (m[0][i] != '.' && m[0][i] == m[1][i] && m[1][i] == m[2][i]) {
            cout << m[0][i] << endl;
            return;
        }
    }
    if (m[1][1] != '.' && m[0][0] == m[1][1] && m[1][1] == m[2][2]) {
        cout << m[1][1] << endl;
        return;
    }
    if (m[1][1] != '.' && m[0][2] == m[1][1] && m[1][1] == m[2][0]) {
        cout << m[1][1] << endl;
        return;
    }
    cout << "ongoing" << endl;
}

int main()
{
    int T;
    cin >> T;
    while (T--) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> m[i][j];
            }
        }
        solve();
    }
}
