#include <bits/stdc++.h>

using i64 = long long;

const int MAXN = 101000;

i64 gcd(i64 a, i64 b) { return a ? gcd(b % a, a) : b; }

struct Frac {

    i64 a, b;

    Frac() : a(0), b(1) {}
    Frac(i64 a_) : a(a_), b(1) {}
    Frac(i64 a_, i64 b_) : a(a_), b(b_) {

        if(!a) b = 1;
        else if(!b) a = 1;
        else {
            
            i64 g = gcd(a, b);
            a /= g, b /= g;

        }
        
    }

    friend bool operator <(const Frac& a, const Frac& b) { return a.a * b.b < b.a * a.b; }

};

int t;
int n, l;
int d[MAXN], v[MAXN];
int index[MAXN];
int prev[MAXN], next[MAXN];
bool visited[MAXN];

Frac calc(int left, int right) {

    i64 dd = d[right] - d[left];
    i64 vv = v[left] - v[right];
    if(vv < 0) vv = -vv, dd = -dd;
    dd = (dd % l + l) % l;
    return Frac(dd, vv);

}

struct Item {

    int left, right;
    Frac time;

    Item() {}
    Item(int left_, int right_) : left(left_), right(right_), time(calc(left, right)) {
        
        if(left > right) std::swap(left, right);

    }

    friend bool operator <(const Item& a, const Item& b) { return b.time < a.time; }

};

void listRemove(int index) {

    next[prev[index]] = next[index];
    prev[next[index]] = prev[index];

}

int main() {

    std::scanf("%d", &t);
    for(int test = 0; test < t; ++test) {
        
        std::scanf("%d%d", &n, &l);
        for(int i = 0; i < n; ++i)
            std::scanf("%d", &d[i]);
        for(int i = 0; i < n; ++i)
            std::scanf("%d", &v[i]);
        for(int i = 0; i < n; ++i)
            index[i] = i, visited[i] = false;
        std::sort(index, index + n, [](int a, int b) { return d[a] < d[b]; });
        for(int i = 0; i < n; ++i)
            prev[index[i]] = index[(i - 1 + n) % n], next[index[i]] = index[(i + 1) % n];
        std::priority_queue<Item> pq;
        for(int i = 0; i < n; ++i)
            pq.push(Item(i, next[i]));
        Frac result = 0;
        for(int i = 0; i < n - 1; ++i) {
            
            Item item;
            while(true) {
                
                item = pq.top();
                pq.pop();
                if(visited[item.left] || visited[item.right]) continue;
                break;

            }
            result = std::max(result, item.time);
            visited[item.left] = true;
            pq.push(Item(prev[item.left], next[item.left]));
            listRemove(item.left);

        }
        std::printf("%lld/%lld\n", result.a, result.b);

    }

}