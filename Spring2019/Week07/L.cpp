#include <bits/stdc++.h>

using ll = long long;

const int MAXS = 200;

int h, w;
int arr[MAXS][MAXS];
bool result[MAXS][MAXS];

int main() {

    std::scanf("%d%d", &h, &w);
    for(int i = 0; i < h + 2; ++i)
        for(int j = 0; j < w + 2; ++j)
            std::scanf("%d", &arr[i][j]);

    bool ok = true;
    
    for(int i = 0; i < h; ++i)
        for(int j = 0; j < w; ++j) {
            
            if(!arr[i][j]) continue;
            if(arr[i][j] > 1) { ok = false; goto done; }
            for(int x = 0; x < 3; ++x)
                for(int y = 0; y < 3; ++y) {

                    int& v = arr[i + x][j + y];
                    if(!v) { ok = false; goto done; }
                    --v;

                }
            result[i][j] = true;
            
        }
    for(int i = 0; i < h + 2; ++i)
        for(int j = 0; j < w + 2; ++j)
            if(arr[i][j]) { ok = false; goto done; }
    
    done:

    if(ok) {

        for(int i = 0; i < h; ++i) {

            for(int j = 0; j < w; ++j)
                std::putchar(".X"[result[i][j]]);
            std::putchar('\n');

        }

    } else std::puts("impossible");

}
