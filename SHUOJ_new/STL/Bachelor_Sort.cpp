#include <bits/stdc++.h>
#define input(n) while(cin >> n)
#define input_2(a, b) while(cin >> a >> b)
#define Tcase int T; cin >> T; while(T--)
#define clr(x, y) memset(x, y, sizeof(x))
#define pb push_back
#define mp make_pair
#define lowbit(x) (x & -x)
#define Lson L, mid, node << 1
#define Rson mid + 1, R, node << 1 | 1
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;

const int maxn = 3e5 + 5;
struct node
{
    char name[35];
    int id;
    int sort_id;
    bool operator < (const node &a)const
    {
        if (strcmp(name, a.name) < 0)
            return true;
        return false;
    }
} bach[maxn];
bool cmp(node a, node b)
{
    return a.id < b.id;
}

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 1; i <= n; i++)
        {
            char name[35];
            scanf("%s", bach[i].name);
            bach[i].id = i;
        }
        sort(bach + 1, bach + 1 + n);
        for (int i = 1; i <= n; i++)
            bach[i].sort_id = i;
        sort(bach + 1, bach + 1 + n, cmp);
        for (int i = 1; i <= n; i++)
            printf("%d\n", bach[i].sort_id);
    }
    return 0;
}
