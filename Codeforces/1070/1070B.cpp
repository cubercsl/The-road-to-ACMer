#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define dbg(args...)                             \
    do                                           \
    {                                            \
        cout << "\033[32;1m" << #args << " -> "; \
        err(args);                               \
    } while (0)
#else
#define dbg(...)
#endif
void err()
{
    cout << "\033[39;0m" << endl;
}
template <template <typename...> class T, typename t, typename... Args>
void err(T<t> a, Args... args)
{
    for (auto x : a) cout << x << ' ';
    err(args...);
}
template <typename T, typename... Args>
void err(T a, Args... args)
{
    cout << a << ' ';
    err(args...);
}
/****************************************************************************************************/

const unsigned BLACK = 1, WHITE = 2;

struct Node
{
    Node* ch[2];
    unsigned mask, tot_mask;
    Node() { mask = tot_mask = 0, ch[0] = ch[1] = nullptr; }
} rt;

void insert(unsigned mask, unsigned ip, int subnet)
{
    Node* o = &rt;
    for (int i = 31; ~i && subnet; i--, subnet--)
    {
        o->tot_mask |= mask;
        int d = ip >> i & 1;
        if (o->ch[d] == nullptr) o->ch[d] = new Node();
        o = o->ch[d];
    }
    o->mask |= mask;
    o->tot_mask |= mask;
}

bool check(Node* o)
{
    if (o->mask & WHITE)
        if (o->tot_mask & BLACK) return true;
    if (o->mask & BLACK)
        if (o->tot_mask & WHITE) return true;
    for (int i = 0; i < 2; i++)
        if (o->ch[i] != nullptr && check(o->ch[i])) return true;
    return false;
}

vector<pair<unsigned, int>> blacks;
void dfs(Node* o, unsigned ip, int level)
{
    if (o->tot_mask == BLACK)
    {
        blacks.emplace_back(ip << level, 32 - level);
        return;
    }
    for (int i = 0; i < 2; i++)
        if (o->ch[i] != nullptr) dfs(o->ch[i], ip << 1 | i, level - 1);
}

tuple<unsigned, unsigned, int> parse(const string& s)
{
    unsigned a, b, c, d;
    unsigned ip;
    char ch;
    int m;
    sscanf(s.c_str(), "%c%u.%u.%u.%u/%d", &ch, &a, &b, &c, &d, &m);
    ip = a << 24 | b << 16 | c << 8 | d;
    ip &= (~0ull) << (32 - m);
    return make_tuple(ch == '+' ? WHITE : BLACK, ip, m);
}

const int BUFSIZE = 1 << 8;
char buf[BUFSIZE];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", buf);
        unsigned mask, ip;
        int subnet;
        tie(mask, ip, subnet) = parse(string(buf) + "/32");
        insert(mask, ip, subnet);
    }
    if (check(&rt)) return puts("-1"), 0;
    dfs(&rt, 0, 32);
    printf("%d\n", static_cast<int>(blacks.size()));
    for (auto& [ip, subnet] : blacks) printf("%u.%u.%u.%u/%d\n", ip >> 24 & 0xff, ip >> 16 & 0xff, ip >> 8 & 0xff, ip & 0xff, subnet);
    return 0;
}