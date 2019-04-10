#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, b, f;
        cin >> n >> b >> f;
        vector<int> a(n - b);
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < n; j++)
                cout << (j >> i & 1);
            cout << endl;
            string s;
            cin >> s;
            for (int j = 0; j < n - b; j++) a[j] |= (s[j] - '0') << i;
        }
        vector<int> ans;
        int block = 0, step = 1 << 5;
        ans.push_back(block + a[0]);
        for (int i = 1; i < n - b; i++)
        {
            if (a[i - 1] > a[i])
                block += step;
            ans.push_back(a[i] + block);
        }
        bool first = false;
        for (int i = 0; i < n; i++)
            if (!binary_search(ans.begin(), ans.end(), i))
            {
                if (first) cout << ' ';
                first = true;
                cout << i;
            }
        cout << endl;
        int op;
        cin >> op;
        assert(~op);
    }
}