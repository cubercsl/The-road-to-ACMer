#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 22;

struct Trie
{
    struct Node
    {
        Node* ch[2];
        int sz;
        long long sum[2];
        void init()
        {
            memset(ch, 0, sizeof(ch));
            memset(sum, 0, sizeof(sum));
            sz = 0;
        }
    } pool[N];
    int alloc;
    Node* newNode()
    {
        pool[alloc].init();
        return &pool[alloc++];
    }
    Node* rt;
    long long ans = 0;
    int cnt[32][2];
    void init()
    {
        alloc = 0;
        memset(cnt, 0, sizeof(cnt));
        rt = newNode();
        ans = 0;
    }
    void insert(int x)
    {
        Node* u = rt;
        for (int i = 30; ~i; i--)
        {
            int d = x >> i & 1;
            if (u->ch[d] == nullptr) u->ch[d] = newNode();
            if (u->ch[d ^ 1] != nullptr)
            {
                ans += 1LL * u->ch[d ^ 1]->sz * (u->ch[d ^ 1]->sz - 1) / 2;
                ans += 1LL * (cnt[i][d ^ 1] - u->ch[d ^ 1]->sz) * u->ch[d ^ 1]->sz;
                ans -= u->sum[d ^ 1];
            }
            u->sum[d] += cnt[i][d] - u->ch[d]->sz;
            cnt[i][d]++;
            u = u->ch[d];
            u->sz++;
        }
    }
} tree;

char* s = "12345678";

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        tree.init();
        for (int i = 0, x; i < n; i++)
        {
            scanf("%d", &x);
            tree.insert(x);
        }
        printf("%lld\n", tree.ans);
    }
}