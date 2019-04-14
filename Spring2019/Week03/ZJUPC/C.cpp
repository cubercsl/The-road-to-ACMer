#include <bits/stdc++.h>

const int MAXN = 2010;

using ll = long long;

int t;
int n, m, a, b;
ll k;
char str[1000];
int mat[MAXN];
bool visited[MAXN];

int& get(int x, int y) { return mat[x * m + y]; }

int calc(int x, int y) {

    int result = 81 * get(x, y) + 27 * get(x - 1, y) + 9 * get(x + 1, y) + 3 * get(x, y - 1) + get(x, y + 1);
    return result;

}

bool run(int& x, int& y, char c) {

    switch(c) {
    case 'U': if(get(x - 1, y) != 1) --x; return false;
    case 'D': if(get(x + 1, y) != 1) ++x; return false;
    case 'L': if(get(x, y - 1) != 1) --y; return false;
    case 'R': if(get(x, y + 1) != 1) ++y; return false;
    case 'P': if(get(x, y) == 2) { get(x, y) = 0; return true; } return false;
    case 'I': return false;
    }

}

int main() {

    std::scanf("%d", &t);
    for(int test = 0; test < t; ++test) {

        std::scanf("%d%d%d%d%lld%s", &n, &m, &a, &b, &k, str);
        for(int i = 0; i < n * m; ++i) {
            
            char c;
            std::scanf(" %c", &c);
            mat[i] = c - '0';

        }
        --a, --b;

        for(int i = 0; i < n * m; ++i)
            visited[i] = false;
        visited[a * m + b] = true;

        int result = 0;
        for(ll step = 0; step < k; ++step) {

            if(run(a, b, str[calc(a, b)])) {
                
                ++result;
                for(int i = 0; i < n * m; ++i)
                    visited[i] = false;
                visited[a * m + b] = true;

            } else if(visited[a * m + b]) break;
            visited[a * m + b] = true;

        }

        std::printf("%d\n", result);

    }

}
