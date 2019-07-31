#include <bits/stdc++.h>
using namespace std;

struct SurrealNumber
{
    int x, y;
    SurrealNumber() {}
    SurrealNumber(int x, int y) : x(x), y(y) {}
    bool operator==(const SurrealNumber& rhs) const
    {
        return x == rhs.x && y == rhs.y;
    }
    bool operator<(const SurrealNumber& rhs) const
    {
        return x * rhs.y < y * rhs.x;
    }
    bool operator<=(const SurrealNumber& rhs) const
    {
        return *this < rhs || *this == rhs;
    }
    friend SurrealNumber half(const SurrealNumber& a, const SurrealNumber& b)
    {
        long long down = max(a.y, b.y);
        long long up = a.x * (down / a.y) + b.x * (down / b.y);
        down <<= 1;
        while (!(up & 1)) up >>= 1, down >>= 1;
        return SurrealNumber(up, down);
    }
};
const SurrealNumber INF(0, -1);

const int N = 9 * 9 * 9 * 9 * 3;
int board[9], nboard[9];
SurrealNumber dp[N];
void init()
{
    for (int i = 0; i < N; i++)
    {
        int t = i;
        for (int j = 0; j < 9; j++) board[j] = t % 3, t /= 3;
        SurrealNumber left = INF, right = INF;
        auto getmask = [&]() {
            int r = 0;
            for (int i = 8; ~i; i--) r = r * 3 + nboard[i];
            return r;
        };
        auto updateLeft = [&]() {
            auto s = dp[getmask()];
            if (left == INF || left < s) left = s;
        };
        auto updateRight = [&]() {
            auto s = dp[getmask()];
            if (right == INF || s < right) right = s;
        };
        for (int j = 0; j < 9; j++)
        {
            if (board[j] == 1)
            {
                int x = j / 3, y = j % 3;

                memcpy(nboard, board, sizeof(board));
                nboard[j] = 0;
                if (x != 0) nboard[j - 3] = 0;
                if (x != 2) nboard[j + 3] = 0;
                updateLeft();
                if (y != 0) nboard[j - 1] = 0;
                if (y != 2) nboard[j + 1] = 0;
                updateLeft();
                memcpy(nboard, board, sizeof(board));
                nboard[j] = 0;
                if (y != 0) nboard[j - 1] = 0;
                if (y != 2) nboard[j + 1] = 0;
                updateLeft();
            }
        }
        for (int j = 0; j < 9; j++)
        {
            if (board[j] == 2)
            {
                memcpy(nboard, board, sizeof(board));
                nboard[j] = 0;
                updateRight();
            }
        }
        if (left == INF && right == INF)
            dp[i] = SurrealNumber(0, 1);
        else if (left == INF)
            dp[i] = {right.x - 1, 1};
        else if (right == INF)
            dp[i] = {left.x + 1, 1};
        else
        {
            assert(left < right);
            SurrealNumber l = INF, r = INF, x(0, 1);
            while (right <= x || x <= left)
            {
                if (right <= x)
                {
                    r = x;
                    if (l == INF)
                        x.x--;
                    else
                        x = half(l, r);
                }
                else
                {
                    l = x;
                    if (r == INF)
                        x.x++;
                    else
                        x = half(l, r);
                }
            }
            dp[i] = x;
        }
    }
}

int main()
{
    init();
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            static char s[10];
            string b;
            for (int i = 0; i < 3; i++)
            {
                scanf("%s", s);
                for (int j = 0; j < 3; j++) b.push_back(s[j << 1]);
            }
            int mask = 0;
            for (int i = 8; ~i; i--) mask = mask * 3 + (b[i] == '#' || b[i] == '.' ? 0 : (b[i] == 'O' ? 1 : 2));
            sum += dp[mask].x * (64 / dp[mask].y);
        }
        // fprintf(stderr, "%d\n", sum);
        if (sum == 0) puts("Second");
        else if (sum > 0) puts("Alice");
        else if (sum < 0) puts("Bob");
    }
}