#include <bits/stdc++.h>
using namespace std;
int a, b, c, d;
int d1[3] = { 3, 0, 1 };
int d2[3] = { 0, 3, 1 };
typedef pair<int, pair<int, pair<int, int> > > piii;
multiset<piii> M;

void dfs(int pos)
{
    if (pos == 7) {
        M.insert(make_pair(a, make_pair(b, make_pair(c, d))));
        return;
    }
    switch (pos)
    {
    case 1:
        for (int i = 0; i < 3; i++) {
            int ta = a, tb = b;
            a += d1[i];
            b += d2[i];
            dfs(pos + 1);
            a = ta;
            b = tb;
        }
        break;
    case 2:
        for (int i = 0; i < 3; i++) {
            int ta = a, tc = c;
            a += d1[i];
            c += d2[i];
            dfs(pos + 1);
            a = ta;
            c = tc;
        }
        break;
    case 3:
        for (int i = 0; i < 3; i++) {
            int ta = a, td = d;
            a += d1[i];
            d += d2[i];
            dfs(pos + 1);
            a = ta;
            d = td;
        }
        break;
    case 4:
        for (int i = 0; i < 3; i++) {
            int tc = c, tb = b;
            c += d1[i];
            b += d2[i];
            dfs(pos + 1);
            c = tc;
            b = tb;
        }
        break;
    case 5:
        for (int i = 0; i < 3; i++) {
            int td = d, tb = b;
            d += d1[i];
            b += d2[i];
            dfs(pos + 1);
            d = td;
            b = tb;
        }
        break;
    case 6:
        for (int i = 0; i < 3; i++) {
            int tc = c, td = d;
            c += d1[i];
            d += d2[i];
            dfs(pos + 1);
            c = tc;
            d = td;
        }
        break;
    }
}

int main()
{
    dfs(1);
    int T;
    cin >> T;
    int kase = 1;
    while (T--)
    {
        int A, B, C, D;
        cin >> A >> B >> C >> D;
        int t = M.count(make_pair(A, make_pair(B, make_pair(C, D))));
        cout << "Case #" << kase++ << ": ";
        if (t == 1)
            cout << "Yes" << '\n';
        else if (t > 1)
            cout << "No" << '\n';
        else
            cout << "Wrong Scoreboard" << '\n';
    }
}
