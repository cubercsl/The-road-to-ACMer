#include <bits/stdc++.h>


const int MAXN = 1000;


int n;
std::map<std::pair<int, int>, int> map;

int main() {

    while(~std::scanf("%d", &n)) {

        map.clear();

        for(int i = 0; i < n; ++i) {
            
            int x, y;
            std::scanf("%d%d", &x, &y);
            ++map[{x, y}];

        }
        int result = 0;
        for(auto i = map.begin(); i != map.end(); ++i)
            for(auto j = std::next(i); j != map.end(); ++j) {
                
                int x0 = i->first.first, y0 = i->first.second, x1 = j->first.first, y1 = j->first.second;
                int dx = x1 - x0, dy = y1 - y0;
                int x2 = x0 + dy, y2 = y0 - dx, x3 = x1 + dy, y3 = y1 - dx;
                int x4 = x0 - dy, y4 = y0 + dx, x5 = x1 - dy, y5 = y1 + dx;
                auto i2 = map.find({x2, y2}), i3 = map.find({x3, y3}), i4 = map.find({x4, y4}), i5 = map.find({x5, y5});
                if(i2 != map.end() && i3 != map.end()) result += i2->second * i3->second;
                if(i4 != map.end() && i5 != map.end()) result += i4->second * i5->second;

            }
        result /= 4;
        std::printf("%d\n", result);

    }

}