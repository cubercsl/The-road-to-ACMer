#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn],ans[maxn];
map<int, int> id;
struct Node{
    int day,val;
    bool operator < (const Node &A) const{
        if (val == A.val) return day < A.day;
        return val < A.val;
    }
};
int main()
{
    int n, m, d;
    scanf("%d%d%d", &n, &m, &d);
    for (int i = 0; i < n;i++){
        scanf("%d", &a[i]);
        id[a[i]] = i;
    }
    sort(a, a + n);
    set<Node> SET;
    SET.insert({1,a[0]});
    ans[id[a[0]]] = 1;
    for (int i = 1; i < n; i++)
    {
        auto it = SET.begin();
        if(it->val + d + 1 <= a[i]){
            int d = it->day;
            ans[id[a[i]]] = d;
            // it->val = a[i];
            SET.erase(it);
            SET.insert({d, a[i]});
        }
        else{
            SET.insert({SET.size() + 1, a[i]});
            ans[id[a[i]]] = SET.size();
        }
    }
    printf("%d\n", SET.size());
    for (int i = 0; i < n;i++)
        printf("%d ", ans[i]);
}