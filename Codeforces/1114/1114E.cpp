#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int l = 0, r = 1e9;
    int op, maxv;
    int tot = 60;
    while (l <= r)
    {
        tot--;
        int mid = l + r >> 1;
        cout << "> " << mid << endl;
        cin >> op;
        if (op)
            l = mid + 1;
        else
            r = mid - 1, maxv = mid;
    }
    mt19937 rng(time(0));
    vector<int> perm(n);
    iota(perm.begin(), perm.end(), 1);
    shuffle(perm.begin(), perm.end(), rng);
    int d = 0;
    for (int i = 0; i < min(n, tot); i++)
    {
        int x = perm[i];
        cout << "? " << x << endl;
        cin >> op;
        d = __gcd(d, maxv - op);
    }
    cout << "! " << maxv - (n - 1) * d << " " << d << endl;
}