#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
int a[maxn];
int t[maxn];
int pres[maxn];
int main()
{
    int n, k, q;
    cin >> n >> k >> q;
    while (n--)
    {
        int l, r;
        cin >> l >> r;
        a[l]++;
        a[r + 1]--;
    }
    for (int i = 1; i < maxn; i++)
        t[i] = t[i - 1] + a[i];
    for (int i = 1; i < maxn; i++)
        pres[i] = pres[i - 1] + (t[i] >= k);
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int ans = pres[r] - pres[l - 1];
        cout << ans << endl;
    }
    return 0;
}
