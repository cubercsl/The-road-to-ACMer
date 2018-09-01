#include <bits/stdc++.h>
using namespace std;

void judge(const vector<int>& v)
{
    for (auto& t : v)
        if (t % 3)
        {
            puts("No");
            return;
        }
    puts("Yes");
}

int main()
{
    int T, kase = 0;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        vector<int> a(n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        printf("Case #%d: ", ++kase);
        judge(a);
    }
}