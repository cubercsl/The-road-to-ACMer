#include <bits/stdc++.h>
 
 
typedef long long i64;
 
 
const int MAXN = 101000;
 
int t, q, m;
 
 
int main() {
     
    std::scanf("%d", &t);
    for(int test = 0; test < t; ++test) {
         
        std::scanf("%d%d", &q, &m);
        std::list<std::pair<i64, i64>> list;
        std::unordered_map<i64, decltype(list)::iterator> map;
        for(int i = 0; i < q; ++i) {
             
            int op;
            i64 v;
            char sss[20];
            std::scanf("%d%s%lld", &op, sss, &v);
            i64 s;
            std::sscanf(sss, "%lld", &s);
            s += std::strlen(sss) * i64(10000000000);
            if(op == 0) {
                 
                auto it = map.find(s);
                if(it != map.end()) {
                     
                    i64 value = it->second->second;
                    list.erase(it->second);
                    list.push_back(std::pair<i64, int>(s, value));
                    it->second = --list.end();
                    std::printf("%lld\n", value);
                     
                } else {
                     
                    list.push_back(std::pair<i64, int>(s, v));
                    map[s] = --list.end();
                    if(int(list.size()) > m) {
                         
                        i64 ss = list.front().first;
                        list.erase(list.begin());
                        map.erase(ss);
                         
                    }
                    std::printf("%lld\n", v);
                     
                }
                 
            } else {
                 
                auto it = map.find(s);
                bool ok = true;
                if(it == map.end()) ok = false;
                else {
                     
                    auto p = it->second;
                    if(v < 0) {
                         
                        if(p == list.begin()) ok = false;
                        else --p;
                         
                    } else if(v > 0) {
                         
                        ++p;
                        if(p == list.end()) ok = false;
                         
                    }
                    if(ok) std::printf("%lld\n", p->second);
                     
                }
                if(!ok) std::puts("Invalid");
                 
            }
             
        }
         
    }
     
}