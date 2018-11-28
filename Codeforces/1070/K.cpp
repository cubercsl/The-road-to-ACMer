#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int a[maxn];
int main()
{
    int n, m,sum=0;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n;i++){
        scanf("%d", a + i);
        sum += a[i];
    }
    if(sum % m){
        puts("No");
        return 0;
    }
    int val = sum / m;
    vector<int> ans;
    int tmp = 0, last = 1;
    for (int i = 1; i <= n; i++)
    {
        tmp += a[i];
        if(tmp == val){
            ans.push_back(i - last + 1);
            last = i+1;
            tmp = 0;
        }
    }
    if(ans.size() != m){
        puts("No");
        return 0;
    }
    else{
        puts("Yes");
        for (auto& v : ans) cout << v << ' ';
        cout << endl;
    }
}