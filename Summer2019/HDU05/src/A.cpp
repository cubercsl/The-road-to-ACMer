#include <bits/stdc++.h>

using u64 = unsigned long long;

const int MAXN = 100000;

int t;
int n, m, q;
int a[MAXN], b[MAXN], k[MAXN];

u64 bs0[MAXN / 64], bs1[MAXN / 64];

void cleanBS(u64* bs, int size) {

    for(int i = 0; i < (size + 63) / 64; ++i) bs[i] = 0;

}
bool getBS(u64* bs, int index) {

    u64 mask = u64(1) << (index % 64);
    return bs[index / 64] & mask;

}
void setBS(u64* bs, int index, bool x) {

    u64 mask = u64(1) << (index % 64);
    if(x) bs[index / 64] |= mask;
    else bs[index / 64] &= ~mask;

}
void xorBS(const u64* bs0, u64* bs1, int index, int size) {

    int base = index / 64;
    int offset = index % 64;
    for(int i = 0; i < (size + 63) / 64; ++i) {

        u64 data = offset ? (bs0[base + i] >> offset) | (bs0[base + i + 1] << (64 - offset)) : bs0[base + i];
        int remain = size - i * 64;
        if(remain < 64) data = (data << (64 - remain)) >> (64 - remain);
        bs1[i] ^= data;

    }

}

int main() {

    std::scanf("%d", &t);
    for(int test = 0; test < t; ++test) {

        std::scanf("%d%d%d", &n, &m, &q);
        for(int i = 0; i < n; ++i)
            std::scanf("%d", &a[i]);
        for(int i = 0; i < m; ++i)
            std::scanf("%d", &b[i]);
        for(int i = 0; i < q; ++i)
            std::scanf("%d", &k[i]);
        int maxn = *std::max_element(a, a + n);
        int maxm = *std::max_element(b, b + m);
        cleanBS(bs0, maxn + 1);
        cleanBS(bs1, maxm);
        for(int i = 0; i < n; ++i)
            setBS(bs0, a[i], 1);
        for(int i = 0; i < m; ++i) {

            int x = b[i];
            for(int j = 0; j <= maxn; j += x)
                xorBS(bs0, bs1, j, std::min(x, maxn + 1 - j));
        }
        for(int i = 0; i < q; ++i)
            std::printf("%d\n", int(getBS(bs1, k[i])));

    }

}