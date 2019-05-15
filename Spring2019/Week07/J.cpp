#include <bits/stdc++.h>

using ll = long long;

const int DIR[4][2] = {{0, 1}, {-1, 0}, {0, 1}, {1, 0}};

const int MAXN = 301000;

int n;
int arr1[MAXN][4];
int arr2[MAXN][4];
std::vector<int> edges[MAXN];
bool visited[MAXN];
int result[MAXN];

int main() {

    std::scanf("%d", &n);
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < 4; ++j)
            std::scanf("%d", &arr1[i][j]);

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < 4; ++j) {

            if(!arr1[i][j]) continue;
            edges[arr1[i][j]].push_back(i);

        }
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < 4; ++j) {

            if(!arr1[i][j]) arr2[i][j] = -1;
            else {
                
                for(int x : edges[arr1[i][j]])
                    if(x != i) { arr2[i][j] = x; break; }

            }

        }
    
    int counts[5] = {};
    for(int i = 0; i < n; ++i) {

        int count = (arr1[i][0] == 0) + (arr1[i][1] == 0) + (arr1[i][2] == 0) + (arr1[i][3] == 0);
        ++counts[count];

    }
    bool ok = true;
    int w = -1, h = -1;
    if(n == 1) {

        if(counts[4] != 1) { ok = false; goto done; }
        w = 1, h = 1;
        result[0] = 0;

    } else {
        
        int s = -1;
        if(counts[2] == n - 2 && counts[3] == 2) {
            
            for(int i = 0; i < n; ++i) {
                
                for(int j = 0; j < 4; ++j) {
                    
                    if(arr2[i][j] >= 0 && arr2[i][(j + 1) % 4] == -1 && arr2[i][(j + 2) % 4] == -1 && arr2[i][(j + 3) % 4] == -1) {
                        
                        std::rotate(arr2[i], arr2[i] + j, arr2[i] + 4);
                        s = i;
                        goto found;

                    }

                }

            }

        } else if(counts[2] == 4) {

            for(int i = 0; i < n; ++i) {
                
                for(int j = 0; j < 4; ++j) {
                    
                    if(arr2[i][j] >= 0 && arr2[i][(j + 1) % 4] == -1 && arr2[i][(j + 2) % 4] == -1 && arr2[i][(j + 3) % 4] >= 0) {
                        
                        std::rotate(arr2[i], arr2[i] + j, arr2[i] + 4);
                        s = i;
                        goto found;

                    }

                }

            }

        }
        { ok = false; goto done; }
        found:
        std::map<int, std::map<int, int>> m;
        // current, x, y
        std::queue<std::tuple<int, int, int>> q;
        m[0][0] = s;
        visited[s] = true;
        q.push({s, 0, 0});
        do {
            
            auto t = q.front();
            q.pop();
            int current = std::get<0>(t);
            int x = std::get<1>(t);
            int y = std::get<2>(t);

            for(int i = 0; i < 4; ++i) {

                int next = arr2[current][i];
                if(next == -1) continue;
                if(visited[next]) continue;
                int dx = x + DIR[i][0], dy = y + DIR[i][1];
                if(dx < 0 || dy < 0 || (m.count(dx) && m[dx].count(dy))) { ok = false; goto done; }

                int r = 0;
                while(arr2[next][r] != current) ++r;
                r = (r - i + 2 + 4) % 4;
                std::rotate(arr2[next], arr2[next] + r, arr2[next] + 4);

                m[dx][dy] = next;
                visited[next] = true;
                q.push({next, dx, dy});

            }

        } while(!q.empty());
        for(int i = 0; i < n; ++i)
            if(!visited[i]) { ok = false; goto done; }
        int maxX = 0, maxY = 0;
        for(auto&& p : m) {

            int x = p.first;
            maxX = std::max(maxX, x);
            for(auto&& q : p.second) {
                
                int y = q.first;
                maxY = std::max(maxY, y);

            }

        }
        ++maxX, ++maxY;
        if(ll(maxX) * maxY != n) { ok = false; goto done; }
        w = maxY, h = maxX;
        for(auto&& p : m) {

            int x = p.first;
            for(auto&& q : p.second) {
                
                int y = q.first;
                int u = q.second;
                if(((y == w - 1) != (arr2[u][0] == -1)) || ((x == 0) != (arr2[u][1] == -1))
                    || ((y == 0) != (arr2[u][2] == -1)) || ((x == h - 1) != (arr2[u][3] == -1))) { ok = false; goto done; }
                result[x * w + y] = u;

            }

        }

    }

    done:
    if(!ok) std::puts("impossible");
    else {

        std::printf("%d %d\n", h, w);
        for(int i = 0; i < n; ++i)
            std::printf("%d%c", result[i] + 1, " \n"[i % w == w - 1]);

    }

}
