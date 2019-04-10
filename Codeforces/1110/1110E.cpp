#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1 << 17;
ll a[N], b[N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%lld", a + i);
    for (int i = 0; i < n; i++) scanf("%lld", b + i);
    if (a[0] != b[0] || a[n - 1] != b[n - 1]) return puts("No"), 0;
    --n;
    for (int i = 0; i < n; i++) a[i] = a[i + 1] - a[i];
    for (int i = 0; i < n; i++) b[i] = b[i + 1] - b[i];
    map<ll, int> cnt;
    for (int i = 0; i < n; i++) cnt[a[i]]++;
    for (int i = 0; i < n; i++) cnt[b[i]]--;
    for (auto& it : cnt)
        if (it.second != 0) return puts("No"), 0;
    puts("Yes");
}