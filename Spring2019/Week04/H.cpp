#include <bits/stdc++.h>


const int MAXN = 100;
int x, y, z;
bool mat[MAXN][MAXN][MAXN];

int main() {
    
    while(~std::scanf("%d%d%d", &x, &y, &z)) {

        for(int i = 0; i < x; ++i)
            for(int j = 0; j < y; ++j)
                for(int k = 0; k < z; ++k)
                    mat[i][j][k] = true;

        for(int i = 0; i < x; ++i)
            for(int j = 0; j < y; ++j) {
                
                int a;
                std::scanf("%d", &a);
                if(a) continue;
                for(int k = 0; k < z; ++k)
                    mat[i][j][k] = false;

            }

        for(int i = 0; i < y; ++i)
            for(int j = 0; j < z; ++j) {
                
                int a;
                std::scanf("%d", &a);
                if(a) continue;
                for(int k = 0; k < x; ++k)
                    mat[k][i][j] = false;

            }

        for(int i = 0; i < z; ++i)
            for(int j = 0; j < x; ++j) {
                
                int a;
                std::scanf("%d", &a);
                if(a) continue;
                for(int k = 0; k < y; ++k)
                    mat[j][k][i] = false;

            }

        int result = 0;
        for(int i = 0; i < x; ++i)
            for(int j = 0; j < y; ++j)
                for(int k = 0; k < z; ++k)
                    result += mat[i][j][k];
        std::printf("%d\n", result);
                
    }

}