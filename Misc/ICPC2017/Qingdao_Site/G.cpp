#include <bits/stdc++.h>
using namespace std;

const int N = 40;
char m[N][N];

int main()
{
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int x = 0, y = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                m[i][j] = ' ';
            }
        }
        m[x][y] = '#';
        int up = n;
        for (int i = 0; i < n; i++) {
            if (!i) {
                for (int j = 1; j < n; j++) {
                    m[x][++y] = '#';
                }
            }
            if ((i - 1) % 4 == 0) {
                for (int j = 1; j < up; j++) {
                    m[++x][y] = '#';
                }
            }
            if ((i - 1) % 4 == 1) {
                for (int j = 1; j < up; j++) {
                    m[x][--y] = '#';
                }
                up -= 2;
            }
            if ((i - 1) % 4 == 2) {
                for (int j = 1; j < up; j++) {
                    m[--x][y] = '#';
                }
            }
            if ((i - 1) % 4 == 3) {
                for (int j = 1; j < up; j++) {
                    m[x][++y] = '#';
                }
                up -= 2;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << m[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}
