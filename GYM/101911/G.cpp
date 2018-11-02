#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
int cnt[maxn];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0,x,y; i < n - 1;i++){
        scanf("%d%d", &x, &y);
        cnt[x]++;
        cnt[y]++;
    }
    if(cnt[n] != n-1){
        puts("NO");
        return 0;
    }
    vector<pair<int, int> > ans;
    for (int i = n - 1; i >= 1; i--)
    {
        if (cnt[i] <= 0) continue;
        vector<int> v;
        v.push_back(i);
        for (int j = i - 1; j >= 1 && cnt[i] > 1; j--)
        {
            if(cnt[j] == 0){
                v.push_back(j);
                cnt[i]--;
                cnt[j]--;
            }
        }
        if(cnt[i] != 1) {
            puts("NO");
            return 0;
        }
        for (int i = 1; i < v.size(); i++)
        {
            ans.push_back({v[i-1], v[i]});
        }
        ans.push_back({n, v.back()});
    }
    puts("YES");
    for(auto &v:ans)
        printf("%d %d\n", v.first, v.second);
}