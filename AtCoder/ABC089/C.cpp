#include <bits/stdc++.h>
using namespace std;

string t = "MARCH";
int cnt[5];

int main()
{
    string s;
    int n;
    cin >> n;
    while (n--)
    {
        cin >> s;
        int pos = t.find(s[0]);
        if (~pos) cnt[pos]++;
    }
    long long ans = 0;
    for (int i = 0; i < 5; i++)
        for (int j = i + 1; j < 5; j++)
            for (int k = j + 1; k < 5; k++)
                ans += 1LL * cnt[i] * cnt[j] * cnt[k];
    cout << ans << endl;
    return 0;
}