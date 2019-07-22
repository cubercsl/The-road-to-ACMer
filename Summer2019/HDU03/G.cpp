#include <bits/stdc++.h>

const int MAXM = 8;

int m;
char buffer[MAXM +1];
bool func[1 << MAXM];

std::vector<bool> extra;
std::vector<std::tuple<int, int, int>> commands;

int allocate(bool x) { extra.push_back(x); return m + 1 + extra.size(); }

void logic(int a, int b, int c) { commands.push_back(std::tuple<int, int, int>(a, b, c)); }

std::map<std::pair<int, int>, int> map;

int main() {

    while(~std::scanf("%d", &m)) {
        
        extra.clear();
        commands.clear();
        map.clear();

        for(int i = 0; i < (1 << m); ++i)
            func[i] = false;
        int count[2] = {};
        for(int i = 0; i < (1 << m); ++i) {
            
            int x;
            std::scanf("%s%d", buffer, &x);
            int index = 0;
            for(int j = 0; j < m; ++j)
                index |= (buffer[j] - '0') << j;
            func[index] = x;
            ++count[x];

        }
        bool initial = count[0] < count[1];

        int one0 = allocate(1);

        int flipped[MAXM];
        for(int i = 0; i < m; ++i)
            logic(one0, i + 1, flipped[i] = allocate(1));

        for(int i = 0; i < (1 << m); ++i) {

            if(func[i] == initial) continue;
            
            int last = one0;
            for(int j = 0; j < m; ++j) {
                
                int b = 1 << j;
                auto key = std::pair<int, int>(j, i & ((2 << j) - 1));
                
                auto it = map.find(key);
                if(it != map.end()) { last = it->second; continue; }

                int current = allocate(0);
                logic(last, i & b ? j + 1 : flipped[j], current);
                map[key] = current;
                last = current;

            }
            logic(one0, last, m + 1);

        }

        if(extra.size() > 800 || commands.size() > 800) {

            std::cerr << "WTF" << std::endl;
            return 1;

        }

        std::printf("%d\n", int(initial));
        std::printf("%d\n", int(extra.size()));
        for(int i = 0; i < int(extra.size()); ++i)
            std::printf("%d%c", int(extra[i]), " \n"[i == int(extra.size()) - 1]);
        std::printf("%d\n", int(commands.size()));
        for(int i = 0; i < int(commands.size()); ++i)
            std::printf("%d %d %d\n", std::get<0>(commands[i]), std::get<1>(commands[i]), std::get<2>(commands[i]));

    }

}