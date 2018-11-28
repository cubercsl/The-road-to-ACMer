#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e5 + 5;
int main()
{
    int n;
    scanf("%d", &n);
    char s[3];
    int val, cnt = 0;
    int ans = 0;
    vector<int> a1, a2, a3;
    for (int i = 0; i < n; i++)
    {
        scanf("%s%d", s, &val);
        if (!strcmp(s, "11"))
        {
            ans += val;
            cnt++;
        }
        else if (!strcmp(s, "01"))
            a1.push_back(val);
        else if (!strcmp(s, "10"))
            a2.push_back(val);
        else
            a3.push_back(val);
    }
    sort(a1.begin(), a1.end());
    reverse(a1.begin(), a1.end());
    sort(a2.begin(), a2.end());
    reverse(a2.begin(), a2.end());
    int tmp = min(a1.size(), a2.size());
    for (int i = 0; i < tmp; i++)
        ans += a1[i] + a2[i];
    for (int i = tmp; i < a1.size(); i++)
        a3.push_back(a1[i]);
    for (int i = tmp; i < a2.size(); i++)
        a3.push_back(a2[i]);
    sort(a3.begin(), a3.end());
    reverse(a3.begin(), a3.end());
    for (int i = 0; i < a3.size() && i < cnt; i++)
        ans += a3[i];
    printf("%d\n", ans);
}