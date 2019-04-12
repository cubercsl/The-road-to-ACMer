#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
struct P
{
    int x, y;
};
P p[maxn];
int n;

bool inOneLine()
{
    bool flag = true;
    for (int i = 1; i < n; i++)
    {
        if (p[i].x != p[0].x)
        {
            flag = false;
            break;
        }
    }
    if (flag) return true;
    flag = true;
    for (int i = 1; i < n; i++)
    {
        if (p[i].x != p[0].x)
        {
            flag = false;
            break;
        }
    }
    if (flag) return true;
    return false;
}
bool diffPoint(){
    map<int,bool> visx, visy;
    for(int i=0;i<n;i++){
        if(!visx[p[i].x])
            visx[p[i].x] = 1;
        else return false;
        if(!visy[p[i].y])
            visy[p[i].y] = 1;
        else return false;
    }
    return true;
}
int main()
{
    int T,kase = 1;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        map<int,int> cnty,cntx;
        map<pair<int,int>,bool> points;
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d", &p[i].x, &p[i].y);
            cntx[p[i].x]++;
            cnty[p[i].y]++;
            points[{p[i].x,p[i].y}] = 1;
        }
        if(inOneLine()){
            printf("Case %d: %d 1\n",kase++,n);
            continue;
        }
        if(diffPoint()){
            printf("Case %d: 2 %lld\n",kase++,1LL * n * (n-1) / 2);
            continue;
        }
        vector<pair<int,int> > vecy;    // number, 
        for(auto &v:cnty){
            vecy.push_back({v.second, v.first});
        }
        sort(vecy.begin(),vecy.end(),[&](const pair<int,int> &A, const pair<int,int> &B){return A.first > B.first;});
        /*
        for(auto &v:vecy){
            printf("%d %d\n",v.first, v.second);
        }
        puts("---------------------");
        */
        ll Max = -1;
        ll ans = 0;
        for(auto &u:cntx){
            int x = u.first;
            int wx = u.second;
            // puts("---------------------------");
            // printf("x = %d, wx = %d\n",x,wx);
            for(auto &v:vecy){
                int wy = v.first;
                int y = v.second;
                // printf("y = %d, wy = %d  Max = %lld\n",y,wy, Max);
                if(points.find({x,y}) == points.end()){
                    if(wx + wy > Max){
                        Max = wx + wy;
                        ans = 1;
                    }
                    else if(wx + wy == Max) ans++;
                    else break;
                }
                else{
                    if(wx + wy -1 > Max){
                        Max = wx + wy - 1;
                        ans = 1;
                    }
                    else if(wx + wy - 1 == Max) ans++;
                    if(Max - (wx + wy -1) > 1) break;
                }
            }
        }
        printf("Case %d: %lld %lld\n",kase++,Max,ans);
    }
}
/*
2
5
1 2
1 3
2 3
4 5
6 7
3
1 2
2 3
3 1
*/