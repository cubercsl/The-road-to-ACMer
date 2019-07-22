#include <bits/stdc++.h>


using u32 = unsigned int;
using u64 = unsigned long long;

const int N = 1000000;
const int M = 1000;
const int P = M;
const int Q = 5;

inline unsigned sfr(unsigned h, unsigned x) {
    return h >> x;
}
inline int f(u64 i, u64 j) {
    u64 w = i * 1000000ll + j;
    int h = 0;
    for(int k = 0; k < 5; ++k) {
        h += int((w >> (8 * k)) & 255);
        h += (h << 10);
        h ^= sfr(h, 6);
    }
    h += h << 3;
    h ^= sfr(h, 11);
    h += h << 15;
    return sfr(h, 27) & 1;
}

std::vector<std::pair<int, int>> map[65535];

int t;
char arr[M][M + 1];

int main(int argc, char** argv) {

    /*if(argc > 1 && !std::strcmp(argv[1], "Generate")) {
        
        int x = 235523, y = 356323;
        std::ofstream out("B.txt");
        out << "1\n";
        for(int i = 0; i < M; ++i) {
            
            for(int j = 0; j < M; ++j) {

                out << f(i + x, j + y);

            }
            out << '\n';

        }
        out.flush();
        return 0;

    }*/

    for(int i = 1; i <= N; i += P) {

        for(int j = 1; j <= N; j += P) {
            
            u64 hash = 0;
            for(int k = 0; k < Q; ++k)
                for(int l = 0; l < Q; ++l)
                    hash = hash * 19260817 + f(i + k, j + l);
            hash %= 65535;
            map[hash].push_back(std::pair<int, int>(i, j));

        }

    }
    
    std::scanf("%d", &t);
    for(int test = 0; test < t; ++test) {

        for(int i = 0; i < M; ++i)
            std::scanf("%s", arr[i]);
        bool ok = false;
        for(int i = 0; i <= M - Q; ++i) {
            
            for(int j = 0; j <= M - Q; ++j) {
                
                u64 hash = 0;
                for(int k = 0; k < Q; ++k)
                    for(int l = 0; l < Q; ++l)
                        hash = hash * 19260817 + (arr[i + k][j + l] - '0');
                hash %= 65535;
                for(auto&& p : map[hash]) {
                    
                    int x = p.first - i, y = p.second - j;
                    if(x < 1 || x + M > N || y < 1 || y + M > N) continue;
                    bool e = false;
                    for(int k = 0; k < M; ++k) {
                        
                        for(int l = 0; l < M; ++l)
                            if(f(x + k, y + l) != arr[k][l] - '0') { e = true; break; }
                        if(e) break;

                    }
                    if(!e) {

                        std::printf("Case #%d :%d %d\n", test + 1, x, y);
                        ok = true;
                        break;

                    }

                }
                if(ok) break;

            }
            if(ok) break;
            
        }
        if(!ok) {
            
            std::cerr << "404 Answer not found" << std::endl;
            return 1;

        }

    }

}