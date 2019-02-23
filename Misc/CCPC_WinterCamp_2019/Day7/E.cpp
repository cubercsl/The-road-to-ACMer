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

typedef long long ll;
const int mod = 119 << 23 | 1;
struct Mat
{
    const static int M = 3;
    int v[M][M];
    Mat() { memset(v, 0, sizeof(v)); }
    inline void unit()
    {
        for (int i = 0; i < M; i++) v[i][i] = 1;
    }
    inline void clear() { memset(v, 0, sizeof(v)); }
    inline void input()
    {
        for (int i = 0; i < M; i++)
            for (int j = 0; j < M; j++)
                scanf("%d", &v[i][j]);
    }
    int* operator[](int x) { return v[x]; }
    const int* operator[](int x) const { return v[x]; }
    Mat operator*(const Mat& B)
    {
        const Mat& A = *this;
        Mat ret;
        for (int k = 0; k < M; k++)
            for (int i = 0; i < M; i++)
                if (A[i][k])
                    for (int j = 0; j < M; j++)
                        ret[i][j] = (ret[i][j] + 1LL * A[i][k] * B[k][j]) % mod;
        return ret;
    }
    Mat operator+(const Mat& B)
    {
        const Mat& A = *this;
        Mat ret;
        for (int i = 0; i < M; i++)
            for (int j = 0; j < M; j++)
            {
                ret[i][j] = (A[i][j] + B[i][j]);
                if (ret[i][j] >= mod) ret[i][j] -= mod;
            }
        return ret;
    }
    int sum()
    {
        int ret = 0;
        for (int i = 0; i < M; i++)
            for (int j = 0; j < M; j++)
            {
                ret = ret + v[i][j];
                if (ret >= mod) ret -= mod;
            }
        return ret;
    }
    void print()
    {
        for (int i = 0; i < M; i++)
            for (int j = 0; j < M; j++)
                printf("%d%c", v[i][j], " \n"[j == M - 1]);
    }
};

const int N = 1 << 17;
int n;
struct Node
{
    Mat t;
    Mat* tag;
    Node *lson, *rson;
    int l, r, d;
    Node(int l, int r, int d) : l(l), r(r), d(d) {}
    void pushup()
    {
        t = lson->t * rson->t;
    }
    void pushdown()
    {
        if (tag == nullptr) return;
        lson->tag = rson->tag = tag;
        lson->t = rson->t = tag[d - 1];
        tag = nullptr;
    }
};

void build(int l, int r, int d, Node*& o)
{
    o = new Node(l, r, d);
    if (l == r)
    {
        if (l < n)
            o->t.input();
        else
            o->t.unit();
        return;
    }
    const int m = l + r >> 1;
    build(l, m, d - 1, o->lson);
    build(m + 1, r, d - 1, o->rson);
    o->pushup();
}

void update(int L, int R, Mat* v, int d, Node* o)
{
    if (L <= o->l && o->r <= R)
    {
        o->tag = v;
        o->t = v[d];
        return;
    }
    o->pushdown();
    const int m = o->l + o->r >> 1;
    if (L <= m) update(L, R, v, d - 1, o->lson);
    if (m < R) update(L, R, v, d - 1, o->rson);
    o->pushup();
}

Mat query(int L, int R, Node* o)
{
    if (L <= o->l && o->r <= R) return o->t;
    const int m = o->l + o->r >> 1;
    o->pushdown();
    Mat ret;
    ret.unit();
    if (L <= m) ret = ret * query(L, R, o->lson);
    if (m < R) ret = ret * query(L, R, o->rson);
    return ret;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    ::n = n;
    Node* rt;
    build(1, 1 << 17, 17, rt);
    for (int i = 0, op, l, r; i < m; i++)
    {
        scanf("%d%d%d", &op, &l, &r);
        if (op == 1)
        {
            Mat* t = new Mat[18];
            t[0].input();
            // t[0].print();
            for (int i = 1; i < 18; i++)
                t[i] = t[i - 1] * t[i - 1];
            update(l, r, t, 17, rt);
        }
        else
        {
            --r;
            Mat v = query(l, r, rt);
            // v.print();
            printf("%d\n", v.sum());
        }
    }
    return 0;
}