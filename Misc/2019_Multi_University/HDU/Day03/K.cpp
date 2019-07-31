#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> int2;

 struct edge {
     int to, rev, cap, cost;
 };

 int n;
 vector<edge> G[maxn];

 void add_edge(int u, int v, int cap, int cost) {
     G[u].push_back((edge){v, (int)G[v].size(), cap, cost});
     G[v].push_back((edge){u, (, , -cost});
 }

 int2 mcmf(int s, int t) {
     //init
     static int h[maxn];        //标号
     , cost = ;
     //solve
     while(true) {
         //dijkstra init
         static int dist[maxn]; //距离
         static int pv[maxn];   //上一个顶点
         static int pe[maxn];   //上一条弧
         memset(dist, 0x33, sizeof dist);
         dist[s] = ;
         priority_queue< int2, vector<int2>, greater<int2> > q;
         q.push(int2(, s));
         //dijkstra
         while(!q.empty()) {
             int2 x = q.top();
             q.pop();
             int u = x.second;
             if(x.first != dist[u]) {
                 continue;
             }
             if(u == t) {
                 break;
             }
             ; i < (int)G[u].size(); ++i) {
                 edge &e = G[u][i];
                 int newcost = e.cost + h[u] - h[e.to];
                  && dist[e.to] > dist[u] + newcost) {
                     dist[e.to] = dist[u] + newcost;
                     q.push(int2(dist[e.to], e.to));
                     pv[e.to] = u;
                     pe[e.to] = i;
                 }
             }
         }
         if(dist[t] == inf) {
             break;
         }
         //augment
         ; i < n; ++i) {
             h[i] = min(h[i] + dist[i], inf);
         }
         int newflow = inf;
         for(int x = t; x != s; x = pv[x]) {
             edge &e = G[pv[x]][pe[x]];
             newflow = min(newflow, e.cap);
         }
         flow += newflow;
         cost += newflow * h[t];
         for(int x = t; x != s; x = pv[x]) {
             edge &e = G[pv[x]][pe[x]];
             e.cap -= newflow;
             G[x][e.rev].cap += newflow;
         }
     }
     return make_pair(flow, cost);
 }

int a[1 << 11];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        MCC mcc(n * 2 + 3);
        int s = n * 2, t = n * 2 + 1;
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        for (int i = 0; i < n; i++)
        {
            mcc.add_directed_edge(s, i, 0, 1, 0);
            mcc.add_directed_edge(i, n + i, 0, 1, -a[i]);
            mcc.add_directed_edge(n + i, t, 0, 1, 0);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (a[j] >= a[i])
                    mcc.add_directed_edge(n + i, j, 0, 1, 0);
            }
        }
        int S = t + 1;
        mcc.add_directed_edge(S, s, 0, k, 0);
        mcc.add_directed_edge(t, S, 0, k, 0);
        printf("%lld\n", -mcc.minimum_cost_circulation().second);
    }
}